#include <stdio.h>
#include <string.h>
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
    msg.msg_type = 1;

    printf("Enter message: ");
    fgets(msg.msg_text, sizeof(msg.msg_text), stdin);

    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);

    printf("Message sent.\n");

    return 0;
}