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
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    string l = "";
    string r = "";
    rep(i,n){
        if(s[i]=='(')cnt++;
        else cnt--;
        if(cnt==-1){
            l+='(';
            cnt=0;
        }
    }
    rep(i,cnt)r+=')';
    string ans = l + s + r;
    cout << ans << endl;
    return 0;
}
