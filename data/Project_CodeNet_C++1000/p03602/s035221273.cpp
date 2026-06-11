#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
ll a[310][310];
ll ans;
ll check(ll x,ll y)
{
        bool f = false;
        for(ll i=1;i<=n;i++)
        {
                if(a[x][i] + a[i][y] < a[x][y]){
                        return -1;
                }
                if(i == x || i == y) continue;
                if(a[x][i] + a[i][y] == a[x][y]){
                        f = true;
                }
        }
        if(f) return 0;

        return 1;
}
int main()
{
        cin >> n;
        for(ll i=1;i<=n;i++)
        {
                for(ll j=1;j<=n;j++){

                        cin >> a[i][j];
                }
        }
        for(ll i=1;i<=n;i++)
        {
                for(ll j=1;j<=n;j++)
                {
                        if(check(i,j) == -1){
                                cout << "-1\n"; return 0;
                        }
                }
        }
        for(ll i=1;i<=n;i++)
        {
                for(ll j=1;j<=n;j++)
                {
                        if(check(i ,j) == 1){
                                ans += a[i][j];
                        }
                }
        }
        cout << ans / 2 << endl;
        return 0;
}
