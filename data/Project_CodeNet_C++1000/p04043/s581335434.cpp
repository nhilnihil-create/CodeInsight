#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using ll = long long;
const ll MOD=1e9+7;
const long long INF = 1LL<<60;

int main() {
    vector<int> input(3);
    rep(i,3) cin >> input.at(i);

    sort(input.begin(), input.end());

    if(input.at(0)==5 && input.at(1)==5 && input.at(2)==7) cout << "YES" << endl;
    else cout << "NO" << endl;
}