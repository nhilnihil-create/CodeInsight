#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    char pre = s[0];
    ll n = s.size();
    ll ans = 0;
    rep(i, 1, n){
        if(pre != s[i]){
            pre = s[i];
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}