#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
void print(ll a, ll digit=30){
    string s = "";
    while(a){
        s += (a & 1 ? '1' : '0');
        a = a >> 1;
    }
    while(s.size() < digit) s += '0';
    reverse(s.begin(), s.end());
    cout << s << endl;
}
int main(){
    ll N, K;
    cin >> N >> K;
    pair<ll, ll> po[N];
    for(ll i = 0; i < N; i++) cin >> po[i].first >> po[i].second;
    vector<ll> v;
    ll digit = 1;
    while((1 << (digit + 1)) <= K) digit++;
    ll now = 1;
    v.push_back(K);
    if(K) v.push_back((1 << digit) - 1);
    for(ll i = digit - 1; i >= 0; i--){
        now = now << 1;
        ll tmp = now;
        if((K >> i) & 1){
            now++;
            for(ll j = i; j > 0; j--) tmp = (tmp << 1) + 1;
            if(tmp <= K) v.push_back(tmp);
        }
    }
    ll ans = 0;
    /*
    for(ll u : v) print(u);
    return 0;
    */
    for(ll u : v){
        ll tmp = 0;
        for(ll i = 0; i < N; i++){
            bool add = 1;
            for(ll d = 0; po[i].first >= (1 << d); d++) if(!(u & (1 << d)) && (po[i].first & (1 << d))) add = 0;
            if(add) tmp += po[i].second;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
