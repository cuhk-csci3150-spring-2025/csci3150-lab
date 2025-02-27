#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct args {
    char *name;
    int age;
};

struct ret {
    bool is_adult;
};

void *hello(void *input) {
    printf("name: %s\n", ((struct args *)input)->name);
    printf("age: %d\n", ((struct args *)input)->age);
    struct ret *retval = malloc(sizeof(struct ret));
    if (((struct args *)input)->age >= 18) {
        retval->is_adult = true;
    }
    else {
        retval->is_adult = false;
    }
    pthread_exit(retval);
}

int main() {
    struct args Allen = {
        .name = "Allen",
        .age = 20
    };

    pthread_t tid;
    pthread_create(&tid, NULL, hello, (void *)&Allen);
    struct ret *res;
    pthread_join(tid, (void **)&res);
    if (res->is_adult) {
        printf("%s has grown up\n", Allen.name);
    }
    else {
        printf("%s is still young\n", Allen.name);
    }
    return 0;
}