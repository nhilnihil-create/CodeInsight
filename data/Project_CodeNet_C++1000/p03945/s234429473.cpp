#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    ll ans = 0;

    for (ll i = 1; i < s.size(); i++){
        if (s[i-1] == s[i]){
            continue;
        }
        else{
            ans++;
        }
    }

    cout << ans << endl;
}