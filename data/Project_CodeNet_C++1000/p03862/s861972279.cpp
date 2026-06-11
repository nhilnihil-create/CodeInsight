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
    int n,x;cin >> n >> x;
    vector<int> a(n);rep(i,n)cin >> a[i];
    ll ans = 0;
    rep(i,n-1)
    {
        if(a[i]+a[i+1]>x)
        {
            ans += (a[i] + a[i + 1]-x);
            if(x-a[i]<0)
            {
                a[i+1] = 0;
            }else
            {
                a[i + 1] = x - a[i];
            }
        }
    }
    cout << ans << endl;

}