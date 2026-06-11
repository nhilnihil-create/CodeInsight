#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

int main() {
    ll n, m, i, j, k;
    string s;
    cin >>s;
    vector<ll> a(27,0);
    for(i=0;i<s.size();i++){
        a[s[i]-'a']++;
    }
    ll ret = s.length();
    ret = ret*(ret-1)/2;
    for(i=0;i<27;i++){
        ret -= a[i]*(a[i]-1)/2;
    }
    cout << ret+1 << endl;
    return 0;
}