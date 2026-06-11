#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;


int main(){
    string s;
    cin >> s;
    int n = s.size();

    ll ans = 0;

    for(int bit = 0; bit < (1 << (n-1)); bit++){
        ll tmp = 0;
        for(int i = 0; i < n; i++){
            if(i == n - 1){
                tmp = tmp*10 + s[i] - '0';
            }else if(bit & (1 << i)){
                ans += tmp*10 + s[i] - '0';
                tmp = 0;
            }else{
                tmp = tmp*10 + s[i] - '0';
            }
        }
        if(tmp > 0) ans += tmp;
    }

    cout << ans << endl;
}