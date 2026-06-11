#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

string S;
vector<char> v;
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> S;
    S += 'A';
    rep(i, S.size()-1) if (S[i]!=S[i+1]) v.pb(S[i]);
    cout << v.size()-1 << endl;
}