#include<cstdio>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<cstring>
#include<map>
 
 
using namespace std;
#define int long long int
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define mp make_pair
#define pb push_back
#define mod 1000000007

int N,K;
int A[20];
//int maxA[20];
signed main(){
    scanf("%lld %lld",&N,&K);
    rep(i,N){
        scanf("%lld",&A[i]);
        //if(i==0)maxA[i]=-1;//maxA+1以上じゃないと見えない
        //else maxA[i]=max(A[i-1],maxA[i-1]);
    }
    int ans=LLINF;
    rep(i,1<<N){
        //Kこ以上を選ぶ全ての建物の選び方について、その建物は必ず見えるようにする
        int cnt=0;
        rep(j,N){
            if((i>>j)%2==1)cnt++;
        }
        if(cnt<K)continue;
        int newmax=-1;
        int money=0;
        rep(j,N){
            if((i>>j)%2==1){//この建物が見えるようにしたい
                money+=max((int)0,newmax-A[j]+1);
                newmax=max(newmax,A[j]+max((int)0,newmax-A[j]+1));
            }else{
                newmax=max(newmax,A[j]);
            }
        }
        ans=min(ans,money);
    }
    printf("%lld\n",ans);
    return 0;
}
