#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = pow(10, 9) + 7;

int main(){
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    int check, s;
    ll ans;
    if(s1[0] == s2[0]){
        ans = 3;
        check = 0;
        s = 1;
    }
    else{
        ans = 6;
        check = 1;
        s = 2;
    }
    for(int i = s; i < n; i++){
        if(s1[i] == s2[i]){
            if(check == 0){
                ans *= 2;
                ans %= mod;
            }
            else if(check == 1){
                ans *= 1;
            }
            check = 0;
        }
        else{
            if(check == 0){
                ans *= 2;
                ans %= mod;
            }
            else if(check == 1){
                ans *= 3;
                ans %= mod;
            }
            check = 1;
            i++;
        }
    }
    cout << ans%mod <<endl;
}