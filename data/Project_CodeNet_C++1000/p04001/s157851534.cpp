#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for (int (i)=0; (i) < (n); (i)++)

int main()
{
    string s; cin >> s;
    int len = s.length();
//    cout << "len = " << len << endl;
    int pattern = len-1;
    ll ans = 0;
    for (int i = 0; i < (1<<pattern); ++i) {
        ll tmp = 0;
        ll index = 0;
        ll stx = 0;
        string st;
//        cout << "i = " << i << endl;
        for (int j = 0; j < pattern; ++j) {
            st.push_back(s[index]);
            index++;
            if ((i >> j) & 0x01) {
//                cout << "st = " << st << endl;
                tmp += stol(st);
                st.clear();
            }
        }
        st.push_back(s[index]);
        tmp += stol(st);
        ans += tmp;
    }
    cout << ans << endl;

}
