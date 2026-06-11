#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> p;
    rep(i, (int)s1.size()){
        if(s1[i] == s2[i]) p.push_back(1);
        else {
            p.push_back(2);
            i++;
        }
    }

    const int mod = 1000000007;
    ll ans = 0;
    if(p[0] == 1) ans = 3;
    else ans = 6;
    for(int i = 1; i < (int)p.size(); i++){
        if(p[i - 1] == 1) ans *= 2;
        else if(p[i] == 2) ans *= 3;
        ans %= mod;
    }
    cout << ans << endl;
}