#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> s(n);
    int ans = 0;
    bool exist_not_multiple_of_ten = false;
    rep(i, n) {
        cin >> s[i];
        ans += s[i];
        if (s[i] % 10) exist_not_multiple_of_ten = true;
    }

    if (ans % 10) {
        cout << ans << endl;
        return 0;
    }

    if (!exist_not_multiple_of_ten) {
        cout << 0 << endl;
        return 0;
    }

    sort(s.begin(), s.end());

    rep(i,n) {
        if(s[i]%10){
            ans -= s[i];
            break;
        }
    }

    cout << ans << endl;

    return 0;
}