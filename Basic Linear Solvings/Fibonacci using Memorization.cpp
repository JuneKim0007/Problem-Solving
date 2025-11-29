#include <stdio.h>

//p1 
void problem1()
{

    int64_t a,b;

    scanf("%lld %lld", &a, &b);
    printf("%lld \n", a+b);
    return;
}

//p2
int fib(int size)
{

    //check basic cases n >1, n =1, n =2;
    if (size <1){ printf("wrong input size n = %d \n", size);}
    if (size ==1){return 1;}
    if (size ==2){return 2;}

    //recursive calls 
    return fib(size-1)+fib(size-2);


    /* for the main
    int size;
    scanf("%d", &size);
    printf("%d \n", fib(size));
    */
}

int main()
{
    int size;
    scanf("%d", &size);
    printf("%d \n", fib(size));
    return 0;

}