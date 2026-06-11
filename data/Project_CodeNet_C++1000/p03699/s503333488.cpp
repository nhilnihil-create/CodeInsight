#include<bits/stdc++.h>
#define int long long
/* #define double long double */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main(){
    int n;
    cin >> n;
    vi s(n);
    rep(i, n){
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    int ans = 0;
    rep(i, n){
        ans += s[i];
        /* cout << s[i] << endl; */
    }
    if(ans % 10 != 0){
        cout << ans << endl;
        return 0;
    }
    int idx = 0;
    int tmp = ans;
    while(tmp- s[idx] >= 0){
        if((tmp - s[idx]) % 10 != 0){
            cout << tmp - s[idx] << endl;
            return 0;
        }
        idx++;
    }
    cout << 0 << endl;
}