#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ld long double
#define zeros(x) x^(x-1)&x
#define pii pair<ll,ll>
#define cd complex<double>
#define dbg(x) cerr<<#x<<": "<<x<<endl;
#define Nmax 200005
#define OFF 100001
using namespace std;

long long n, x, v[Nmax], mn[Nmax];
long long fin, ans;

int main()
{
    cin >> n >> x;
    for (int i=1;i<=n;i++) cin >> v[i],mn[i] = v[i];
    fin = 1e18;
    for (int i=0;i<n;i++){
        ans = 0;
        for (int j=1;j<=n;j++){
            if (j-i > 0) mn[j] = min(mn[j], v[j-i]);
            else mn[j] = min(mn[j], v[n-(i-j)]);
            ans += mn[j];
        }
        ans += 1LL * x * i;
        fin = min(fin, ans);
    }
    cout << fin << '\n';
    return 0;
}
