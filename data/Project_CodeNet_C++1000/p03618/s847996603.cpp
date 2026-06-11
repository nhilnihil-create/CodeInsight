#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1e9;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

ll Sum(int n) {
    ll ret = 0;
    for(int i = 1;i <= n;i++) {
        ret += i;
    }
    return ret;
}

int main() {
    string S;
    cin >> S;
    vector<int> vec(26);
    for(int i = 0;i < S.size();i++) {
        vec.at(S.at(i) - 'a')++;
    }
    ll ret = 0;
    for(int i = 0;i < 26;i++) {
        ret += Sum(vec.at(i));
    }
    cout << Sum(S.size()) + 1 - ret << endl;
}