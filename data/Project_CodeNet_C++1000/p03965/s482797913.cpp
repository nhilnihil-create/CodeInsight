#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii ;
const int mod = 1e9 + 7;

ll binPow(ll x, ll y, ll md = mod){
    ll res = 1;
    x %= mod;
    while(y){
        if(y & 1){
            res = (res * x) % mod;
        }
        y >>= 1;
        x = (x * x) % mod;
    }
    return res;
}

void solve(){
   string s;
   cin >> s;
   int win = 0, lose = 0;
   for(int i = 0; i < s.length(); ++i){
       win += i % 2 && s[i] == 'g';
       lose += !(i % 2) && s[i] == 'p';
   }
   cout << win - lose << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}

