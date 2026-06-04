#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char msg[100];

    mkfifo("myfifo", 0666);

    int fd = open("myfifo", O_WRONLY);

    while (1) {
        printf("Enter Message: ");
        fgets(msg, sizeof(msg), stdin);

        write(fd, msg, strlen(msg)+1);

        if (strncmp(msg, "exit", 4) == 0)
            break;
    }

    close(fd);
    return 0;
}