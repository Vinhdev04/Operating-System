#include "stdio.h"
#include "pthread.h"

// Ham thuc thi tuyen
void* do_loop(void* data)
{
    int i; // bo dem cho tuyen
    int me = *((int*) data); // ep kieu 
    
    for(i = 0;  i < 5; i++)
    {
        sleep(1);
        printf(" '%d' - Got '%d' \n", me,i);
    }
    // cham dut tuyen
    pthread_exit(NULL);
}

int main(int agrc, char* argv[])
{
    int thr_id ; // bo dinh tuyen
    pthread_t p_thread; // cau truc luu tru cac thong tin ve tuyen
    int a = 1; // dinh danh cho tuyen thu 1
    int b = 2; // dinh danh cho tuyen thu 2
    
    // tao tuyen
    thr_id = pthread_create (&p_thread, NULL, do_loop, (void*) &a);
    
    // chay do_loop trong tuyen chinh
    do_loop((void*)&b);
    return 0;
}

