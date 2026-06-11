#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1000000000;

int main() {
    map<int,bool>mp;

    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    ans++;
    mp[a] = true;

    if (!mp[b]){
        ans++;
        mp[b] = true;
    }

    if (! mp[c])ans++;
    cout << ans << endl;
}