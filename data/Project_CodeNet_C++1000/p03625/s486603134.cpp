//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;
#define pb push_back
#define fi first
#define se second
#define in insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int mod = 1e9 + 7;
void solve(){
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        m[x]++;
    }
    vll a;
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        int x = (*it).se;
        while (x > 1) {
            a.pb((*it).fi);
            x -= 2;
            if (a.size() == 2) break;
        }
        if (a.size() == 2) break;
    }
    if (a.size() == 2) cout << a[0] * a[1];
    else cout << 0;
}
int main(){
    speed;
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
    }
}