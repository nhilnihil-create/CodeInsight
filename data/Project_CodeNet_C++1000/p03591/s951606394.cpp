#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    string yaki = "";
    rep(i,4){
        yaki += s[i];
    }
    if(yaki == "YAKI") cout <<"Yes" << endl;
    else cout << "No" << endl;
    return 0;
}