/**
*    created: 24.06.2020 00:47:46
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pcnt(bit) __builtin_popcount(bit)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int bit = 0; bit < (1 << (n-1)); bit++) {
        string s1 = "";
        int siz = 0;
        rep(i,n-1) {
            s1.insert(siz, s.substr(i,1));
            siz++;
            if ((bit >> i) & 1) {
                s1.insert(siz,"+");
                siz++;
            }
        }
        s1.insert(siz,s.substr(s.size()-1,1));
        int l = 0;
        int sum = 0;
        rep(i,s1.size()) {
            if (s1[i] != '+') continue;
            sum += stol(s1.substr(l,i-l));
            l = i+1;
        }
        sum += stol(s1.substr(l));
        ans += sum;
    }
    cout << ans << endl;
    return 0;
}