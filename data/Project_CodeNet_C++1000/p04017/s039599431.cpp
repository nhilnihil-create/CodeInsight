#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    int n;
    cin>>n;
    int x[n];
    rep(i,n)cin>>x[i];
    int l,q;
    cin>>l>>q;
    int r[20][n];
    rep(i,n){
        int to=upper_bound(x,x+n,x[i]+l)-x;
        r[0][i]=to-1;
    }
    for(int i=1;i<20;++i){
        for(int j=0;j<n;++j){
            r[i][j]=r[i-1][r[i-1][j]];
        }
    }
    rep(i,q){
        int a,b;
        cin>>a>>b;
        --a,--b;
        if(a>b)swap(a,b);
        int t=0;
        for(int j=19;j>=0;--j){
            if(r[j][a]<b){
                a=r[j][a];
                t+=(1<<j);
            }
        }
        cout<<t+1<<endl;
    }
}
