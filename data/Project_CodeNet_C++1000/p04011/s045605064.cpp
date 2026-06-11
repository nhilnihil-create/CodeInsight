#include<stdio.h>
#include<stdlib.h>

int main()
{
    long N,K,X,Y,z,pro;
    scanf("%ld %ld %ld %ld",&N,&K,&X,&Y);
    if(K<=N)
    {
        z=K*X;
        pro=(N-K)*Y;
        printf("%ld\n",z+pro);
    }
   else{z=N*X;
        printf("%ld\n",z);
        }
    return 0;
}