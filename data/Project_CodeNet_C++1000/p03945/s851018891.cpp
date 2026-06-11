#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    string s; cin >> s;
    int slen = s.length();
    int cnt = 0;
    for(int i = 1; i < slen; ++i) {
        if(s.at(i) != s.at(i-1)) cnt++;
    }
    cout << cnt << endl;
}