#include <bits/stdc++.h>
#define rep(a,n) for (int a = 0; a < (n); ++a)
using namespace std;
using ll = long long;
typedef pair<ll,ll> P;
typedef pair<P,ll> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;


int main(){
    string s;
    cin >> s;
    int l = s.size();
    int cnt = 0;
    rep(i,l-1){
        if(s[i]!=s[i+1])cnt++;
    }
    cout << cnt << endl;

    return 0;
}