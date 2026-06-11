#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int s[110];

int main(){
    int n;
    cin >> n;
    bool flag = true;
    int tot = 0;
    rep(i, n){
        cin >> s[i];
        tot += s[i];
        flag &= (s[i]%10==0);
    }

    if (flag) {
        cout << 0 << endl;
    }

    else if (tot%10 != 0) cout << tot << endl;

    else{
        sort(s, s+n);
        rep(i, n){
            if (s[i]%10!=0){
                tot -= s[i];
                break;
            }
        }
        cout << tot << endl;
    }



    return 0;
}
