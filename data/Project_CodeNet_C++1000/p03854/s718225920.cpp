#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;

int main() {
    string s; cin >> s;reverse(s.begin(),s.end());
    string ans = "YES";
    while(s.length() != 0){
        if(s.substr(0,5) == "maerd" || s.substr(0,5) == "esare"){
            s.erase(0,5);
        }else if(s.substr(0,6) == "resare"){
            s.erase(0,6);
        }else if(s.substr(0,7) == "remaerd"){
            s.erase(0,7);
        }else{
            ans = "NO";
            break;
        }
    }
    cout << ans;
    
}

