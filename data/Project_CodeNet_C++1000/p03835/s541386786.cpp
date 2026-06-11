#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int k, s;
    cin >> k >> s;

    int ans = 0;
    rep(i, k + 1)
    {
        rep(j,k+1){
            if(0<=s-i-j && s-i-j<=k){
                ans++;
            }
        }
    }

    cout << ans << endl;
    return (0);
}
