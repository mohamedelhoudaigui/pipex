#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_CHILDREN 10

int main() {
    int num_children;

    printf("Enter the number of child processes (1 to %d): ", MAX_CHILDREN);
    scanf("%d", &num_children);
    if (num_children < 1 || num_children > MAX_CHILDREN) {
        printf("Invalid number of child processes.\n");
        return EXIT_FAILURE;
    }
    int **pipes = malloc(sizeof(int*) * num_children);
    // Create pipes
    for (int i = 0; i < num_children; ++i) {
        pipes[i] = malloc(sizeof(int) * 2);

        if (pipe(pipes[i]) == -1) {
            perror("Pipe creation failed");
            exit(EXIT_FAILURE);
        }
    }
    // Create child processes
    for (int i = 0; i < num_children; ++i) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) { // Child process
            close(pipes[i][1]); // Close write end of the pipe
            // Read data from the pipe
            char buffer[100];
            ssize_t bytesRead = read(pipes[i][0], buffer, sizeof(buffer));
            if (bytesRead == -1) {
                perror("Read from pipe failed");
                exit(EXIT_FAILURE);
            }
            // Process the data (just printing for simplicity)
            printf("Child %d received: %.*s\n", i + 1, (int)bytesRead, buffer);
            // Close read end of the pipe in the child
            close(pipes[i][0]);
            exit(EXIT_SUCCESS);
        } else { // Parent process
            close(pipes[i][0]); // Close read end of the pipe
            // Send data to the child processes
            char message[50];
            sprintf(message, "Hello from parent to child %d!", i + 1);
            write(pipes[i][1], message, sizeof(message));
            // Close write end of the pipe in the parent
            close(pipes[i][1]);
        }
    }
    // Wait for all child processes to finish
    for (int i = 0; i < num_children; ++i) {
        wait(NULL);
    }
    // Free allocated memory
    for (int i = 0; i < num_children; ++i) {
        free(pipes[i]);
    }
    free(pipes);
    return 0;
}
