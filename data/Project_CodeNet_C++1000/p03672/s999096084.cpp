#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 0;
    rep(i, 1, n){
        if((n - i) % 2 == 1) continue;
        ll len = (n - i);
        if(s.substr(0, len/2) == s.substr(len/2, len/2)) ans = max(ans, len); 
    }
    cout << ans << endl;
    return 0;
}