#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    string s;
    cin >> s;
    ll ans = 0;
    int n = s.size();
    rep(bit, (1<<(n-1))){
        ll tmp=0;
        rep(i, n-1){
            tmp *= 10;
            tmp += s[i] - '0';
            if (bit & (1<<i)) {
                ans += tmp;
                tmp = 0;
            }
        }
        tmp *= 10;
        tmp += s.back() - '0';
        ans += tmp;
    }

    cout << ans << endl;

    return 0;
}