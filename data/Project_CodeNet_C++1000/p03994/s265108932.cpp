#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

ll comb(ll n, ll r) {
    ll ret = 1;
    for (ll i = 0; i < r; i++) ret = ret * (n - i);
    for (ll i = 1; i <= r; i++) ret /= i;
    return ret;
}

int main(){
    string s; cin >> s;
    ll k,d,sum = 0; cin >> k;
    queue<char> q;

    rep(i,s.length()){

        if(i == s.length()-1){
            sum = (k-sum)%26;
            d = (int)(s[i] - 'a');
            d = (sum+d)%26;

            q.push((char)('a' + d));

            break;
        }

        if(s[i] == 'a'){
            q.push('a');
            continue;
        }

        d = ('z' - s[i] + 1);
        if(sum+d <= k){
            sum += d;
            q.push('a');
        }else q.push(s[i]);


    }

    while(!q.empty()) {
        cout << q.front();
        q.pop();
    }
}