#include <iostream>
#include <string>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    int ans = 0;
    cin >> s;
    rep(i,s.size()-1) {
        if (s[i] != s[i+1]) {
            ans++;
        }
    }
    cout << ans << "\n";
}