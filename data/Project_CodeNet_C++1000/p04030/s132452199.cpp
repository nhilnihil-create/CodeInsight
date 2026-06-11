#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
    string s; cin >> s;
    stack <ll> st;
    rep(i, s.size()) {
        if (s.at(i) == '0') st.push(0);
        else if (s.at(i) == '1') st.push(1);
        else if (st.size()) st.pop();
    }
    vector <ll> v;
    ll n = st.size();
    rep(i, n) {
        v.push_back(st.top()); st.pop();
    }
    rep(i, v.size()) cout << v.at(v.size()-1-i);
    cout << endl;
}