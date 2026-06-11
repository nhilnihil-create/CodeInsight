#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;


int main() {
    string s; cin >> s;
    sort(s.begin(),s.end());
    string ans = "yes";
    for(int i = 0;i < s.length()-1;i++){
        if(s[i] == s[i+1]){
            ans = "no";
        }
    }
    cout << ans;
}


