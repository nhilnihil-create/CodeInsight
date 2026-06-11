#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1000000007;

int main(){
    int n; cin >> n;
    string s, t; cin >> s >> t;
    bool v = false, h = false;
    ll ans = 1;
    int idx = n;
    if(n >= 2){
        if(s[0] == s[1]){
            h = true;
            ans = 6;
            idx = 2;
        }
        if(s[0] != s[1]){
            v = true;
            ans = 3;
            idx = 1;
        }
    }   
    for(int i = idx; i < n; i++){
        if(i == n-1){
            if(v){
                ans *= 2;
                ans %= mod;
                break;
            }
        }
        if(s[i] == s[i+1]){
            if(v){
                ans *= 2;
                ans %= mod;
            }
            if(h){
                ans *= 3;
                ans %= mod;
            }
            ++i;
            v = false;
            h = true;
            continue;
        }
        if(s[i] != s[i+1]){
            if(v){
                ans *= 2;
                ans %= mod;
            }
            h = false;
            v = true;
            continue;
        }
    }
    if(n == 1) ans = 3;
    cout << ans << endl;
}