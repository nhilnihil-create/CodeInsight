#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using namespace std;
using str = string;
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;

int main() {
    str S;
    cin >> S;
    int N = S.size();

    ll ans = 0;
    for(int bit = 0; bit < (1 << N); bit++) {
        ll st = 0;
        for(int i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                st = st*10 + (S[i]-'0');
            }
            else {
            ans += st;
            st = 0;
            }
        }
        ans += st;
    }
    cout << ans << endl;
    return 0;
}