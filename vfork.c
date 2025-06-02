#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pid = vfork();  // SYSTEM CALL
    if (pid == 0) {
        printf("Child process\n");
        _exit(0);  // Safely exit
    } else {
        printf("Parent process\n");
    }
    return 0;
}
