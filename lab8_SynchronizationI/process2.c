/*process-2.c*/
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc, char *argv[]) {

    char *c = "This is CSCI3150--An operating system course.\n";
    // specify no buffering for stderr
    setbuf(stderr, NULL);

    while (*c != '\0') {
        fputc(*c, stderr);
        c++;
        sleep(rand() % 2 + 1);
    }
    return 0;
}