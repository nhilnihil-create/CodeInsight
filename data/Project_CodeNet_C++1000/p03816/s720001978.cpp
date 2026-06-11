#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    int n; cin >> n;
    vector<int> Avec(n, 0);
    for(int i = 0; i < n; ++i) cin >> Avec.at(i);
    map<int, int> mcnt;
    for(int i = 0; i < n; ++i) {
        mcnt[Avec.at(i)]++;
    }

    int k = mcnt.size();
    if(k % 2 == 0) cout << k-1 << endl;
    else cout << k << endl;
}