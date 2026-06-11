#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};
int main(){
    ll N,W;cin>>N>>W;
    vector<ll> w(N),v(N);
    for(int i=0;i<N;++i){
        cin>>w[i]>>v[i];
    }
    ll m=w[0];
    for(int i=0;i<N;++i){
        w[i]-=m;
    }
    ll DP[N+1][N+1][301];
    for(int i=0;i<=N;++i){
        for(int j=0;j<=N;++j){
            for(int k=0;k<=300;++k){
                DP[i][j][k]=0;
            }
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<=N;++j){
            for(int k=0;k<=300;++k){
                DP[i+1][j][k]=max(DP[i+1][j][k],DP[i][j][k]);
                if(j>0&&k>=w[i]){
                    DP[i+1][j][k]=max(DP[i+1][j][k],DP[i][j-1][k-w[i]]+v[i]);
                }
            }
        }
    }
    ll ans=0;
    for(int j=0;j<=N;++j){
        for(int k=0;k<=300;++k){
            if(j*m+k<=W) ans=max(ans,DP[N][j][k]);
        }
    }
    cout<<ans<<endl;
    return 0;
}