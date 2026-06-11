#include <bits/stdc++.h>
#define DEBUG(x) cout << #x << " = " << x << endl
#define pb push_back
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
const int MAXN = 100005;
int x[MAXN];
int var[MAXN];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }

    for (int i = 1; i <= n; i++)
    {
        var[i] = n-i+1;
    }

    int place = 1;
    for (int i = 1; i <= n; i++)
    {
        if (x[i] < 2*(i-place+1)-1)
        {
            var[place] = i-place+1;
            place++;
        }
    }

    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * (ll) (var[i]) % MOD;
    //    cout << var[i] << " ";
    }
    cout << ans;
    return 0;
}


