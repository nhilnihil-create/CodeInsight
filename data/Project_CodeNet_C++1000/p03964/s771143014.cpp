#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    ll nowt=1, nowa=1;
    rep(i,n){
        ll t,a;cin>>t>>a;
        ll n1 = (nowt+(t-1))/t;
        ll n2 = (nowa+(a-1))/a;
        ll tn = max(n1,n2);
        nowt = t*tn; nowa = a*tn;
    }
    cout<<nowa+nowt<<endl;
}