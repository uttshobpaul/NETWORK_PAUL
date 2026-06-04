#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key = ftok("progfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    struct message msg;

    msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);

    printf("Received Message: %s\n", msg.msg_text);

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}