#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<set>
#include<cstring>

 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define LLIandI pair<long long int , int>
#define ll long long


long long int A[100004];
long long int B[100004];
ll int N;
long long sum=0;
int main(){
    scanf("%lld",&N);
    rep(i,N){
        scanf("%lld",&A[i]);
        if(i>0)B[i-1]=A[i]-A[i-1];
        sum+=A[i];
    }
    B[N-1]=A[0]-A[N-1];
    long long int X;
    if((2*sum)%(N*(N+1))==0){
        X=(long long int)(2*sum/(N*(N+1)));
    }else{
        printf("NO\n");return 0;
    }
    long long int ysum=0;
    rep(i,N){
        ll int y=(ll int)((B[i]+(N-1)*X)/N);
        if((B[i]+(N-1)*X)%N==0&&y<=X){
            ysum+=y;
        }else{
            printf("NO\n");return 0;
        }
    }
    if(ysum==X*(N-1)){
        printf("YES\n");return 0;
    }
    printf("NO\n");return 0;
}
