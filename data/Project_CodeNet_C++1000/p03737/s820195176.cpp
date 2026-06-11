#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    rep(i,3){
        string s;
        cin >> s;
        char ans = toupper(s[0]);
        cout << ans;
    } 
    cout << endl;
    return 0;
}