#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define PB push_back
using namespace std;
typedef pair<int, int> P1;
typedef pair<int, pair<int, int> > P2;
static const int INF = 1ll<<60;
static const int dx[] = { 1, -1, 0, 0, };
static const int dy[] = { 0, 0, 1, -1 };
static const int mod = 1000000007;

int N;
int A[100005];
char op[100005];
int dp[100005][5];
//    [i項目][i項目までに開いているかっこの数]

int solve(){
    for(int i=0;i<100005;++i)for(int j=0;j<5;++j)dp[i][j]=-INF;
    dp[0][0] = A[0];
    for(int i=0;i<N-1;++i){
        for(int j=0;j<=3ll;++j){
            int f;
            if(j%2==0)f=1;
            else f=-1;
            int t1 = f*A[i+1];
            if(op[i+1]=='+'){
                dp[i+1][j] = max(dp[i][j]+t1,dp[i+1][j]);
                if(j!=0)dp[i+1][j-1] = max(dp[i][j]+t1,dp[i+1][j-1]);
            }
            else {
                dp[i+1][j] = max(dp[i][j]-t1,dp[i+1][j]);
                dp[i+1][j+1] = max(dp[i][j]-t1,dp[i+1][j+1]);
                if(j!=0)dp[i+1][j-1] = max(dp[i][j]-t1,dp[i+1][j-1]);
            }
        }
    }
    int ans=-INF;
    for(int i=0;i<=3;++i)ans=max(dp[N-1][i],ans);
    return ans;
}


signed main(){
    cin>>N;
    op[0]='+';
    for(int i=0;i<N;++i){
        cin>>A[i];
        if(i!=N-1)cin>>op[i+1];
    }
    cout<<solve()<<endl;
}
