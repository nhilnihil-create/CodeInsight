#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    ll n = s.size();
    ll ans = 1e18;
    for(char c = 'a'; c <= 'z'; c++){
        string t = s;
        bool f = false;
        for(auto e : t) if(e == c) f = true;
        if(!f) continue;
        ll cnt = 0;
        while(true){
            bool f = true;
            for(auto e : t) if(e != c) f = false;
            if(f) break;
            string next(t.size()-1, 'a');
            for(int i = 0; i < t.size()-1; i++){
                if(t[i] == c || t[i+1] == c) next[i] = c;
                else next[i] = t[i];
            }
            cnt++;
            t = next;
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}