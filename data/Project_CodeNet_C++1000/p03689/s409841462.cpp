#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int read()
{
    char c;int s=0,t=1;
    while(!isdigit(c=getchar()))if(c=='-')t=-1;
    do{s=s*10+c-'0';}while(isdigit(c=getchar()));
    return s*t;
}
/*------------------------------------------------------------*/
const int inf=0x3f3f3f3f;
 
int N,M,n,m;
 
int main()
{
    scanf("%d%d%d%d",&N,&M,&n,&m);
    if(N%n==0&&M%m==0){printf("No");return 0;}
    printf("Yes\n");
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++)
            printf("%d ",i%n||j%m?1100:-1100*(n*m-1)-1);
        printf("\n");
    }
    return 0;
}