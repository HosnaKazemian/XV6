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

   
    int pid = fork(); 

    if (pid < 0) {
        // Fork failed
        printf(1, "fork failed\n");
        exit();
    } else if (pid == 0) {
    
        printf(1, "This is the child process with PID %d\n", getpid());
        int tid = thread_create(thread_func, &counter, 0);
        if(tid>0){
            thread_joins(tid);
        }
        printf(1, "Counter after thread: %d\n", counter);
        exit();
    
    } else {
    
        printf(1, "This is the parent process with PID %d, child PID %d\n", getpid(), pid);  
        wait();
    }
   
    exit();
    
}



















// #include "types.h"
// #include "user.h"

// void thread_func(void *arg1, void *arg2) {
//     sleep(1);
//     int *counter = (int*)arg1;
//     for (int i = 0; i < 10; i++) {
//         (*counter)++;
//         printf(1, "Counter in thread: %d\n", *counter);
//     }
//     exit();
// }



// // void thread_function(void *arg1, void*arg2) {
// //     int *result = malloc(sizeof(int));
// //     *result = 52;
// //     exit();
// // }

// int main(int argc, char *argv[]) {
//     int counter = 0;
//     printf(1, "Counter initially: %d\n", counter);
//     // int * result=0;
//     // thread_create(thread_func, &counter, 0);
//     thread_create(thread_func ,&counter, 0);
//     thread_join();
   

//     printf(1, "Counter after thread: %d\n", counter);
//     // printf(1, "result after thread: %d\n", *result);
//     exit();
// }
//     // if(tid==0){
//     //     printf(1,"hi i am the thread");
//     //     exit();
//     // }
//     // if(tid>0){
//     //     printf(1," hi i am the process itself");
//     //     thread_join();
//     // }
   

   
