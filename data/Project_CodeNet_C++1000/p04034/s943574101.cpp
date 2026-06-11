#include <cstdio>
#define MAXN 100007
#include <cstring>

char mayRed[MAXN];
int numOfBall[MAXN];

int main(void)
{
    mayRed[1]=1;
    int i,N,M;
    int x,y;
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++)
    {
        numOfBall[i]=1;
        mayRed[i]=0;
    }
    mayRed[1]=1;

    for(i = 0;i<M;i++)
    {
        scanf("%d%d",&x,&y);
        if(mayRed[x])
        {
            mayRed[y]=1;
        }
        numOfBall[y]+=1;
        numOfBall[x]-=1;
        if(numOfBall[x]==0)
        {
            mayRed[x]=0;
        }
    }
    int r = 0;
    for(i=1;i<=N;i++)
    {
        r+=mayRed[i];
    }
    printf("%d\n",r);

    return 0;
}