#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(i,n) for(int i = 1; i <= (int)(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

//const ll mod=1000000007;

int main() {
    ll x;
    cin >> x;
    ll ans = 0;
    if(x <= 6) {
        cout << 1 << endl;
        return 0;
    }
    ans += x / 11;
    ans *= 2;
    x %= 11;
    if(x == 0) cout << ans << endl;
    else if(x <= 6) cout << ans + 1 << endl;
    else cout << ans + 2 << endl;
}