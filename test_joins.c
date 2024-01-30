#include "types.h"
#include "user.h"

void thread_func(void *arg1, void *arg2) {
    //  sleep(1);
    // int *counter = (int*)arg1;
    // // printf(1,"in thread , tid %d\n",getpid());
    // for (int i = 0; i < 1; i++) {
    //     // printf(1, "-----Counter in thread: %d pid = -----\n", *counter,getpid());
    //     (*counter)++;
       
    // }
    exit();
}

int main(int argc, char *argv[]) {
    int counter = 0;
    // printf(1, "-----------Counter initially: %d pid = --------------\n", counter,getpid());

   
    int pid = fork(); 

    if (pid < 0) {
        // Fork failed
        printf(1, "fork failed\n");
        exit();
    } else if (pid == 0) {
    
        // printf(1, "child c%d\n", pid);
        int tid1 = thread_create(thread_func, &counter, 0);
        int tid2 = thread_create(thread_func, &counter, 0);
        // printf(1,"tid %d\n", tid1);
        if(tid1>0){
            thread_joins(tid1);
        }
         if(tid2>0){
            thread_joins(tid2);
        }
        printf(1, "Counter after thread: %d\n", counter);
        exit();
    
    } else {
        int alaki=0;
        alaki++;
        // alaki++;
        // alaki++;
        // printf(1, "parent p%d\n", pid);  
        
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
   

   
