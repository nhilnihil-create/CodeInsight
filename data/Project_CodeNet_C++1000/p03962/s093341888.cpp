#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    map<int,bool>mp;
    int cnt = 0;
    if (mp[a] == false)cnt++;
    mp[a] = true;
    if (mp[b] == false)cnt++;
    mp[b] = true;
    if (mp[c] == false)cnt++;
    mp[c] = true;
    
    cout << cnt << endl;
}