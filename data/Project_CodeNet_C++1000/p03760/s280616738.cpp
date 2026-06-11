#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    string o,e;
    cin >> o >> e;
    int n = e.length() + o.length();
    int ne = 0, no = 0;
    string ans = "";
    rep(i,n){
        if(i%2 == 0){
            ans += o[no];
            no++; 
        }else{
            ans += e[ne];
            ne++;
        }
    }
    cout << ans << endl;
    return 0;   
}