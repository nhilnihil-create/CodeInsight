#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
const int MOD = 1000000007;



int main() {
    string o,e; cin >> o >> e;
    string ans;
    for(int i = 0;i < e.length();i++){
        ans += o[i];
        ans += e[i];
    }
    if(o.length()>e.length()){
       
        ans+=o[o.length()-1];
    }
    cout << ans;
}


