#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
int n,m;
cin>>n>>m;
vector<int> a(n),b(n),c(m),d(m);
rep(i,n){
    cin>>a[i]>>b[i];
}
rep(i,m){
    cin>>c[i]>>d[i];
}
vector<int>move(n);
rep(i,n){
    ll dist=INF;
    int idx;
    rep(j,m){
        ll tmp_dist=abs(a[i]-c[j])+abs(b[i]-d[j]);
        if(dist>tmp_dist){
            dist=tmp_dist;
            idx=j+1;
        }
    }
    move[i]=idx;
}
rep(i,n){
    cout<<move[i]<<endl;
}

return 0;
}