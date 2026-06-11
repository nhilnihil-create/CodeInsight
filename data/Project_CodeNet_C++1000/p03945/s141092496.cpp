#include <iostream>
#include <string>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    char s[100010];
    int ans = 0;
    cin >> s;
    rep(i, 100000) {
        if ((s[i] == 'B' && s[i+1] == 'W') || (s[i] == 'W' && s[i+1] == 'B')){
            ans++;
        }
    }
    cout << ans << "\n";
}
