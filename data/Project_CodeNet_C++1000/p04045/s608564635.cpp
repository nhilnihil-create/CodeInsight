#include <stdio.h>
#include <math.h>
#define MAX_N 10000
#define MAX_K 9

int N, K;
int D[MAX_K];

int check(int a){
    int i, j, n, m;
n=a;
while(n!=0){
        m = n%10;
        for (j=0; j<K; j++)
            if (m==D[j]) return 1;
            n/=10;
}
    return 0;
}

int main(){
    int i;
    scanf("%d%d", &N, &K);
    for (i=0; i<K; i++)
        scanf("%d", &D[i]);

    i=N;
    while (1)
    {
        if(check(i)==0)break;
        else
        {
            i++;
        }
    }

    printf("%d\n", i);

    return 0;
}
