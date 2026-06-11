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
typedef pair<int,pii> P;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};

int main(){
    int N,M;cin>>N>>M;
    vector<int> A(M),B(M),C(M);
    vector<vector<ll> > d(N,vector<ll>(N,INF));
    for(int i=0;i<N;++i) d[i][i]=0;
    for(int i=0;i<M;++i){
        cin>>A[i]>>B[i]>>C[i];
        A[i]--;B[i]--;
        d[A[i]][B[i]]=d[B[i]][A[i]]=C[i];
    }
    for(int k=0;k<N;++k){
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(d[i][k]==INF||d[k][j]==INF) continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int ans=0;
    for(int k=0;k<M;++k){
        bool ok=true;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(i==j) continue;
                if(d[i][A[k]]+C[k]+d[B[k]][j]==d[i][j]){
                    ok=false;
                }
            }
        }
        if(ok) ans++;
    }
    cout<<ans<<endl;
    return 0;
}