#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char msg[100];

    mkfifo("fifo1", 0666);
    mkfifo("fifo2", 0666);

    int fdw = open("fifo1", O_WRONLY);
    int fdr = open("fifo2", O_RDONLY);

    while (1) {
        printf("Process1: ");
        fgets(msg, sizeof(msg), stdin);

        write(fdw, msg, strlen(msg)+1);

        if (strncmp(msg, "exit", 4) == 0)
            break;

        read(fdr, msg, sizeof(msg));
        printf("Process2: %s", msg);
    }

    close(fdw);
    close(fdr);

    return 0;
}