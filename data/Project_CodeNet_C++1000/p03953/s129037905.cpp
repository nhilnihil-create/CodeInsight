#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=998244353,MAX=100003,INF=1<<30;

int go[MAX][80];

int main(){
    
    int N;cin>>N;
    vector<ll> X(N),diff(N-1),to(N-1),ans(N);
    for(int i=0;i<N;i++) cin>>X[i];
    for(int i=0;i<N-1;i++) diff[i]=X[i+1]-X[i];
    
    ll M,K;cin>>M>>K;
    vector<int> A(M);
    for(int i=0;i<M;i++) cin>>A[i];
    
    iota(all(to),0);
    
    for(int i=0;i<M;i++){
        swap(to[A[i]-2],to[A[i]-1]);
    }
    
    for(int i=0;i<N-1;i++){
        go[i][0]=to[i];
    }
    
    for(int j=1;j<70;j++){
        for(int i=0;i<N-1;i++){
            go[i][j]=go[go[i][j-1]][j-1];
        }
    }
    
    ans[0]=X[0];
    
    for(int i=0;i<N-1;i++){
        int id=i;
        for(int j=0;j<63;j++){
            if(K&(1LL<<j)){
                id=go[id][j];
            }
        }
        ans[i+1]=ans[i]+diff[id];
    }
    
    for(ll a:ans) cout<<a<<endl;
    
}

