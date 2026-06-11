#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string s, t;
    cin >> n >> s >> t;
  	int p = -1;
    rep(i,n){
        bool ok = true;
        rep(j,n-i){
            if(s[i+j] != t[j]){
                ok = false;
                break;
            }
        }
        if(ok){
            p = i;
          	break;
        }
    }
    if(p != -1) cout << n + p << endl;
  	else cout << 2*n << endl;
    return 0;
}
