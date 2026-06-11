#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string s;
    cin >> s;
    string ans = "";
    rep(i,s.size()){
        if(i%2==0) ans = ans+s[i];
    }
    cout << ans << endl;
}
