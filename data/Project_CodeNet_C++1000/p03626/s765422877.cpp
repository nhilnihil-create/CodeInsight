#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1<<30;
const ll LINF = 1LL<<58;
const ll mod = 1000000007;

int main(){
    int n;
    string s[2];
    cin >> n >> s[0] >> s[1];
    ll ans = 1;
    int i = 0, cnt;
    bool t = false, p, start = true;
    while(i < n){
        p = t;
        if(s[0][i] == s[1][i]) {
            t = true;
            i++;
        }
        else {
            t = false;
            i += 2;
        }
        if(start){
            start = false;
            if(t) cnt = 3;
            else cnt = 6;
            ans = ans * cnt % mod;
            continue;
        }
        if(t && p) cnt = 2;
        else if(t && !p) cnt = 1;
        else if(!t && p) cnt = 2;
        else cnt = 3;
        ans = ans * cnt % mod;
    }
    cout << ans << endl;
    return 0;
}