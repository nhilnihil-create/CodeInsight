#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#define MAXN 100007

using namespace std;
typedef long long ll;

char mayRed[MAXN];
int numOfBall[MAXN];

int main()
{
    int i,n,m;
    int x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++){
        numOfBall[i]=1;
        mayRed[i]=0;
    }
    mayRed[1]=1;
    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        if(mayRed[x])
            mayRed[y]=1;
        numOfBall[y]++;
        numOfBall[x]--;
        if(numOfBall[x]==0)
            mayRed[x]=0;
    }
    int r=0;
    for(i=1;i<=n;i++)
        r+=mayRed[i];
    printf("%d\n",r);
    return 0;
}

