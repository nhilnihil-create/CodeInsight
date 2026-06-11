#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll N;
    ll l = 0, r = 0;
    string L, R;
    string S;
    cin >> N >> S;
    for(ll i = 0;i < S.size();i++) {
        ll j = S.size() - i - 1;
        if(S[i] == '(') l++;
        else l = max(l - 1, 0LL);
        if(S[j] == ')') r++;
        else r = max(r - 1, 0LL);
    }
    L.resize(r, '(');
    R.resize(l, ')');
    S.insert(0, L);
    S.insert(S.size(), R);
    cout << S << endl;
    return 0;
}
