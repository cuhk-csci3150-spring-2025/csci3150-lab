#define _GNU_SOURCE
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

/* print the error message and exit */
#define handle_error_en(en, msg)                                                         \
    do {                                                                                 \
        errno = en;                                                                      \
        perror(msg);                                                                     \
        exit(EXIT_FAILURE);                                                              \
    } while (0)

int main(int argc, char *argv[]) {
    int s, j;
    int CPUNUM = get_nprocs();
    cpu_set_t cpuset;
    pthread_t thread;

    thread = pthread_self(); // get the id of the current thread

    CPU_ZERO(&cpuset); // empty the cpu set
    for (j = 0; j < CPUNUM - 1; j++)
        CPU_SET(j, &cpuset); // add each cpu to the cpu set except the last one

    /* Set affinity mask to include CPUs but the last one */
    s = pthread_setaffinity_np(thread, sizeof(cpu_set_t), &cpuset);

    if (s != 0)
        handle_error_en(s, "pthread_setaffinity_np");

    /* Check the actual affinity mask assigned to the thread */
    s = pthread_getaffinity_np(thread, sizeof(cpu_set_t), &cpuset);
    if (s != 0)
        handle_error_en(s, "pthread_getaffinity_np");

    printf("Set returned by pthread_getaffinity_np() contained:\n");
    for (j = 0; j < CPUNUM; j++)
        if (CPU_ISSET(j, &cpuset))
            printf("CPU %d is set affinity\n", j);
        else
            printf("CPU %d is not set affinity\n", j);

    exit(EXIT_SUCCESS);
}