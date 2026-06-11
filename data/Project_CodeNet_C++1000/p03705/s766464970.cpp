#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

ll n,a,b,maxv,minv;

int main(){
    cin>>n>>a>>b;
    if(a>b) cout<<0<<"\n";
    else if(n==1 && a!=b) cout<<0<<"\n";
    else{
        minv=a*(n-1)+b;
        maxv=b*(n-1)+a;
        cout<<maxv-minv+1<<"\n";
    }
    return 0;
}