#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;




int main(){
    ll n,l;
    cin >> n >> l;
    vector<ll>a(n);
    rep(i,n)cin>>a[i];
    ll flag = -1;
    rep(i,n-1){
        if(flag!=-1)break;
        if(a[i]+a[i+1]>=l){
            flag = i+1;
        }
    }
    if(flag==-1)cout << "Impossible" << endl;
    else{
        cout << "Possible" << endl;
        for(int i=1;i<flag;i++){
            cout << i << endl;
        }
        for(int i=n-1;i>flag;i--){
            cout << i << endl;
        }
        cout << flag << endl;
        
    }
    return 0;
}
