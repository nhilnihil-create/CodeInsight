#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;

string s;

int main(){
    cin >> s;
    int g=0,p=0;
    int n = s.size();
    rep(i,n){
        if(s[i]=='g')g++;
        else p++;
    }
    int wp = n/2;
    int wg = n-wp;
    cout << wp - p << endl;

    return 0;
}
