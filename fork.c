#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = fork();  // SYSTEM CALL
    if (pid == 0)
        printf("Child process\n");
    else
        printf("Parent process\n");
    return 0;
}
