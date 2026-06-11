#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    string s;
    cin >> s;
    ll ans = 99999;
    rep(i, 26){
        char ch = i+'a';
        ll prev = 0, m = 0;
        bool z = true;
        rep(j, s.length()){
            if(s[j] == ch){
                if(z) m = max(m, j - prev);
                else m = max(m, j - prev - 1);
                z = false;
                prev = j;
            }
        }
        if(m < s.length()-prev-1) m = s.length()-prev-1;
        
        ans = min(ans, m);
        //printf("%c %lld\n", ch, m);
    }
    cout << ans << endl;
    return 0;
}