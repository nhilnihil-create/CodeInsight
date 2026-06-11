#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    int a,z;
    bool flag = true;
    rep(i,n){
        if(flag && s[i] == 'A'){
            a = i;
            flag = false;
        }
        if(!flag && s[i] == 'Z'){
            z = i;
        }
    }
    cout << z - a + 1 << endl;
    return 0;
}