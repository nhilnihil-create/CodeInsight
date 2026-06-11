#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int main()
{
    ll w, h;
    cin >> w >> h;

    priority_queue<pll, vector<pll>, greater<pll>> que; 
    rep(i, 0, w)
    {
        int p;
        cin >> p;
        que.push(make_pair(p, 0));
    }
    rep(i, 0, h)
    {
        int p;
        cin >> p;
        que.push(make_pair(p, 1));
    }
    
    ll ans = 0;
    while (que.size() > 0)
    {
        ll weight, wh;
        tie(weight, wh) = que.top();
        que.pop();

        // cout << weight << ' ' << wh << ' ' << ans << endl;
        if (wh == 0)
        {
            ans += (h + 1) * weight;
            --w;
        }
        else
        {
            ans += (w + 1) * weight;
            --h;
        }
    }
    cout << ans << endl;
    return 0;
}