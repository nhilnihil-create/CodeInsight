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
        char v[len]; v[ti] = S[index];
        index++;
        ti++;
        for (int j = 0; j < bitnum; ++j) {
            if ((i>>j) & 0x01) {
                v[ti] = '\0';
                //cout << "v = " << v << endl;
                ti = 0;
                ll ii;
                sscanf(v, "%ld", &ii);
                ans += ii;
                v[ti] = S[index];
                index++; ti++;
            }
            else {
                v[ti] = S[index];
                index++;
                ti++;
            }
        }
        v[ti] = S[index];
        ti++;
        v[ti] = '\0';
        //cout << "v = " << v << endl;
        ll ii;
        sscanf(v, "%ld", &ii);
        ans += ii;
        //cout << endl;
    }    
    cout << ans << endl;
    
}
