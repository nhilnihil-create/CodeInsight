#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
//typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;


int main(){
    int n,m;
    cin >> n >> m;
    vector<int>k(n,0);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        k[a]++;k[b]++;
    }
    rep(i,n){
        if(k[i]%2==1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
