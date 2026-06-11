//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m; cin>>n>>m;
    string ans="No";
    vector<string> a(n),b(m);
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];
    rep(i,n-m+1)rep(j,n-m+1){
        int cnt=0;
        rep(k,m)rep(l,m){
            if(a[i+k][j+l]==b[k][l]) cnt++;
        }
        if(cnt==m*m) ans="Yes";
    }
    cout<<ans<<endl;
}