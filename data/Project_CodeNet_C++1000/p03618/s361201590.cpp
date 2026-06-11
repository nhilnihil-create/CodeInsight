#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();


int main() {
    string s;
    cin >> s;
    unordered_map<char, ll> cnt;
    ll ans = 0;
    for(char c: s) {
        cnt[c] += 1;
    }
    ll n = s.size();
    ans = n*(n+1) / 2;
    for(auto p: cnt) {
        ll freq = p.second;
        ans -= freq*(freq+1) / 2;
    }
    cout << ans+1 << endl; // original
    return 0;
}


