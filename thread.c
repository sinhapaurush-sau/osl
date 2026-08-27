#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include <sys/syscall.h>


int a[3] = {1,2,3};

void *t1(){
    printf("THREAD STARTED\n");

    int p = getpid();
    int t = syscall(SYS_gettid);
        printf("PID: %d\n", p);
    printf("TID: %d\n", t);


    int max = a[0];
    for (int i=0;i<3;i++){
        if(max<a[i]){
            max = a[i];
        }
    }
    printf("MAX: %d\n", max);

    printf("THREAD ENDED\n\n");
    pthread_exit(NULL);
}

void *t2(){
    printf("THREAD STARTED\n");

    int p = getpid();
    int t = syscall(SYS_gettid);
    printf("PID: %d\n", p);
    printf("TID: %d\n", t);

    int sum = 0;
    for (int i=0;i<3;i++){
        sum+= a[i];
    }
    printf("SUM: %d\n", sum);

    printf("THREAD ENDED\n\n");
    pthread_exit(NULL);

}

void *t3(){
    printf("THREAD STARTED\n");

    int p = getpid();
    int t = syscall(SYS_gettid);
    printf("PID: %d\n", p);
    printf("TID: %d\n", t);

    int min = a[0];
    for (int i=0;i<3;i++){
        if(min>a[i]){
            min = a[i];
        }
    }
    printf("MIN: %d\n", min);

    printf("THREAD ENDED\n\n");
    pthread_exit(NULL);

}

int main(){
    pthread_t a,b,c;
        pthread_create(&b, NULL, t1, NULL);
        pthread_join(b, NULL);
        pthread_create(&a, NULL, t2, NULL);
        pthread_join(a, NULL);
        pthread_create(&c, NULL, t3, NULL);
        pthread_join(c, NULL);
    return 0;
}