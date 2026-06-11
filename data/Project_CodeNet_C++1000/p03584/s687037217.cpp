#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;cin >> n >> k;
    vector<int> a(n),b(n);
    rep(i,n){
        cin >> a[i] >> b[i];
    }
    vector<int> p;
    int v=0;
    for(int i=30;i>0;i--){
        if(k&(1<<i)){
            v+=1<<i;
        }
        if(v+(1<<(i-1))-1<=k){
            p.push_back(v+(1<<(i-1))-1);
        }
    }
    p.push_back(k);
    ll ans=0;
    for(int x:p){
        ll res=0;
        rep(i,n){
            if((x|a[i])==x){
                res+=b[i];
            }
        }
        chmax(ans,res);
    }
    cout << ans << endl;
}