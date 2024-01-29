#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"
#include "x86.h"

#define n_threads 10

int counter = 0;

lock_t* lock;

void thread_func(void* arg1, void* arg2) {
  int i;
  lock_acquire(lock);
  for (i = 0; i < 100; i++) {
    counter += 1;
  }
  lock_release(lock);
  exit();
}

int main(int argc, char *argv[]) {
  lock_init(lock);
  int i, tid[n_threads];


  for (i = 0; i < n_threads; i++) {
    tid[i] = thread_create(thread_func, 0, 0);
    if (tid[i] == -1) {
      printf(1, "Error creating thread %d\n", i);
      exit();
    }
  }

 
  for (i = 0; i < n_threads; i++) {
    if (thread_join() == -1) {
      printf(1, "Error joining thread %d\n", tid[i]);
      exit();
    }
  }


  if (counter != n_threads * 100) {
    printf(1, "Test failed: counter expected to be %d but was %d\n", n_threads * 100, counter);
  } else {
    printf(1, "Test passed: counter was %d\n", counter);
  }

  exit();
}
