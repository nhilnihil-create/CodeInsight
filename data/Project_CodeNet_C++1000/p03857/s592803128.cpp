#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n , m , k;
ll p[200005];
ll a[200005] , b[200005];
ll id[200005];
ll X[200005] , Y[200005];
map< pair<ll,ll> , ll> mp;
ll fs(ll x)
{
        return p[x] == x ? x : p[x] = fs(p[x]);
}
void us(ll ax , ll bx)
{
        ax = fs(ax);
        bx = fs(bx);
        p[bx] = ax;
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        cin >> n >> m >> k;
        for(ll i=1;i<=n;i++) p[i] = i;
        for(ll i=1;i <=m;i++)
        {
                cin >> a[i] >> b[i];
                us(a[i] , b[i]);
                //id[a[i]] = id[b[i]] = -1;
        }
        memset(id , -1 , sizeof id);
        ll cnt = 0;
        for(ll i=1;i<=n;i++)
        {
                ll cap = fs(i);
                if(id[cap] == -1) {
                        id[cap] = ++cnt;
                }
                X[i] = id[cap];
                //X[i] = id[cap];
        }
        cnt = 0;
        for(ll i=1;i<=n;i++) p[i] = i;
        for(ll i=1;i<=k;i++)
        {
                cin >> a[i] >> b[i];
                us(a[i] , b[i]);
                //id[a[i]] = id[b[i]] = -1;
        }
        memset(id , -1 , sizeof id);
        for(ll i=1;i<=n;i++)
        {
                ll cap = fs(i);
                if(id[cap] == -1) {
                        id[cap] = ++cnt;
                }
                Y[i] = id[cap];
        }
        for(ll i=1;i<=n;i++)
        {
                //cout << X[i] << " " << Y[i] << endl;
                mp[make_pair(X[i] , Y[i])]++;
        }
        for(ll i=1;i<=n;i++)
        {
                cout << mp[make_pair(X[i] , Y[i])] << " ";
        }
        return 0;
}
