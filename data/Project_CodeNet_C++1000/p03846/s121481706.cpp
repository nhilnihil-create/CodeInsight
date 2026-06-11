#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n;cin >> n;
    vector<int> a(n); rep(i,n) cin >> a[i];
    bool judge = false;
    vector<int> counter(n);rep(i, n)counter[i]==0;
    rep(i, n) counter[a[i]]++;
    ll ans = 1;
    if(n%2==0)
    {
        for(int i = 1; i < n; i+=2)
        {
            if(counter[i]!=2)
            {
               ans = 0;
               break;
            }
            ans *= 2;
            ans %= MOD;
        }
    }else
    {
        for (int i = 0; i < n; i += 2)
        {
            if(i==0)
            {
                if(counter[i]!=1)
                {
                    ans = 0;
                    break;
                }
                continue;
            }
            if (counter[i] != 2)
            {
                ans = 0;
                break;
            }
            ans *= 2;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}