#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char msg[100];

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    int fdr = open("fifo1", O_RDONLY);
    int fdw = open("fifo2", O_WRONLY);

    while (1) {
        read(fdr, msg, sizeof(msg));
        printf("Process1: %s", msg);

        if (strncmp(msg, "exit", 4) == 0)
            break;

        printf("Process2: ");
        fgets(msg, sizeof(msg), stdin);

        write(fdw, msg, strlen(msg)+1);
    }

    close(fdr);
    close(fdw);

    return 0;
}