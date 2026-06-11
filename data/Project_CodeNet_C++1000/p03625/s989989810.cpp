#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2000000000
#define infLL 2000000000000000000
#define MAX 1000002
#define sf(a) scanf("%d", &a)
#define sfl(a) scanf("%lld", &a)
#define pf(a) printf("%d ", a)
#define pfl(a) printf("%lld\n", a)
#define Case(t) printf("Case %d: ", t)
#define pii pair<int, int>
#define MOD 1000000007
#define mod 998244353
#define PI acos(-1.0)
#define eps 1e-9
#define mem(a, b) memset(a, b, sizeof(a))
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

void solve()
{
    int n;
    cin>>n;
    vector<ll>a(n);
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a.begin(), a.end());
    int cnt = 0;
    ll tot[2] = {0};
    for(int i = n-1; i >= 1; i--)
    {
        if(a[i]==a[i-1])
        {
            tot[cnt] = a[i];
            cnt++;
            i--;
        }
        if(cnt==2)
            break;
    }
    cout<<tot[0] * tot[1]<<endl;
}

int main()
{
    FASTIO;
    solve();

    return 0;
}
