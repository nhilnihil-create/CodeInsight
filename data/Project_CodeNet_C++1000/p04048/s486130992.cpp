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

ll int f_shikaku(ll int A,ll int B){
    ll int a=max(A,B);
    ll int b=min(A,B);
    if(a%b==0)return 2*(ll int)(a/b)*b-b;
    return f_shikaku(a%b,b)+2*(ll int)(a/b)*b;
}
int main(void){
    ll int N,X;
    scanf("%lld %lld",&N,&X);
    ll int ans;
    ans=f_shikaku(X,N-X)+N;
    printf("%lld\n",ans);
}
