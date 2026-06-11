#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9
const ll inff = 1000000000000000000; //10^18

int main(){
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> t(n);
    rep(i, n) cin >> t[i];

    sort(all(t));
    ll nowt = t[0] + k, cou = 1, ans = 1;
    for(int i = 1; i < n; i++) {
        if(t[i] <= nowt) {
            if(c > cou) cou++;
            else {
                ++ans;
                cou = 0;
                nowt = t[i]+k;
                i--;
            }
        }
        else {
            ++ans;
            cou = 0;
            nowt = t[i]+k;
            i--;
        }
    }
    cout << ans << endl;

    return 0;
}