#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    ll n = s.size();
    string ans = "";
    for (ll i = 0; i < n; i++){
        if (s[i] == '0'){
            ans.push_back('0');
        }
        else if (s[i] == '1'){
            ans.push_back('1');
        }
        else{
            if (ans != ""){
                ans.pop_back();
            }
        }
    }
    cout << ans << endl;
}