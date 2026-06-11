#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    bool flag = true;
    rep(i,n){
        if(s[i]%10 != 0){
            flag = false;
        }
    }
    if(flag) {
        cout << 0 << endl;
        return 0;
    }

    int total = 0, min = 0;
    rep(i,n) total += s[i];
    sort(s.begin(), s.end());
    rep(i,n){
        if(s[i]%10 != 0){
            min = s[i];
            break;
        }
    }
    if(total%10 != 0) cout << total << endl;
    else cout << total - min << endl;
    return 0;
}