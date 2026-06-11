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
    for(int i = 0; i < s.length();i++){
        if(i % 2 == 0){
            cout << s[i];
        }
    }
}


