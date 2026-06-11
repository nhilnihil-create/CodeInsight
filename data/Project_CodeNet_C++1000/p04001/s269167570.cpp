#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    string S; cin >> S;
    int len = S.length();
    ll bitnum = len - 1;
    ll ans = 0;
    for (int i = 0; i < (1 << bitnum); ++i) {
        ll index = 0;
        ll ti = 0;
        string tmps; tmps.push_back(S[index]);
        index++;
  
        for (int j = 0; j < bitnum; ++j) {
            if ((i>>j) & 0x01) {
                ans += stol(tmps);
                tmps.clear();
                tmps.push_back(S[index]);
                index++;
            }
            else {
                tmps.push_back(S[index]);
                index++;
             }
        }
        tmps.push_back(S[index]);
        ans += stol(tmps);
    }    
    cout << ans << endl;
    
}
