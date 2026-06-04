#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char msg[100];

    mkfifo("myfifo", 0666);

    int fd = open("myfifo", O_RDONLY);

    while (1) {
        read(fd, msg, sizeof(msg));

        printf("Received: %s", msg);

        if (strncmp(msg, "exit", 4) == 0)
            break;
    }

    close(fd);
    return 0;
}