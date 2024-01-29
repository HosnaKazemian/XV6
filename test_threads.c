#include "types.h"
#include "user.h"

void thread_func(void *arg1, void *arg2) {
    sleep(1);
    int *counter = (int*)arg1;
    for (int i = 0; i < 10; i++) {
        (*counter)++;
        printf(1, "Counter in thread: %d\n", *counter);
    }
    exit();
}

int main(int argc, char *argv[]) {
    int counter = 0;
    printf(1, "Counter initially: %d\n", counter);

    thread_create(thread_func, &counter, 0);
    thread_join();

    printf(1, "Counter after thread: %d\n", counter);
    exit();
}
