#include "userprog/syscall.h"
#include <stdio.h>
#include <syscall-nr.h>
#include "threads/interrupt.h"
#include "threads/thread.h"
#include "threads/vaddr.h"

static void syscall_handler (struct intr_frame *);

void
syscall_init (void) 
{
  intr_register_int (0x30, 3, INTR_ON, syscall_handler, "syscall");
}

static void
syscall_handler (struct intr_frame *f UNUSED) 
{
  printf ("system call!\n");
  thread_exit ();
}

void exit(int status){
  struct thread *t = thread_current();

  printf("%s: exit(%d)\n", t->name, status);

  thread_exit();
}

void check_user_address(void *addr) {
  // 포인터가 user 영역 주소를 가리키는지 확인
  if (!is_user_vaddr(addr) || is_kernel_vaddr(addr) || addr == NULL) {
    exit(-1);
  }
}

void get_argument(void *esp, int *arg , int count) {
  uint32_t *sp = esp;
  check_user_address(sp + 4);
  int cnt = 0;
  for (;count != 0; count--) {
    arg[cnt] = sp + 4;
    cnt ++;
  }
}
