#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    int n;
    cin >> n >> s;
    int max = 0;
    int ans = 0;
    rep(i,n){
        if(s[i] == 'I'){
            ans++;
            if(ans > max) max = ans;
        }else{
            ans--;
        }
    }
    cout << max << endl;
    return 0;
}