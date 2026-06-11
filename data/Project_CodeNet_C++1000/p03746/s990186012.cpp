#include <bits/stdc++.h>
using namespace std;
int main()
{
    using ll = long long;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n+1);
    for(int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    ll s = n+1;
    for(int i = 1; i <= n; i++)
    {
        ll tmp = a[i].size();
        s = min(s, tmp);
    }

    vector<ll> ans_l;
    vector<ll> ans_r;
    vector<bool> used(n+1);
    used[s] = true;
    ll cand = s;
    while(true)
    {
        bool upd = false;
        for(int i = 0; i < a[cand].size(); i++)
        {
            if(!used[a[cand][i]])
            {
                cand = a[cand][i];
                ans_l.push_back(cand);
                used[cand] = true;
                upd = true;
                break;
            }
        }
        if(upd) continue;
        break;
    }
    cand = s;
    if(a[s].size() >= 2)
    {
        while(true)
        {
            bool upd = false;
            for(int i = 0; i < a[cand].size(); i++)
            {
                if(!used[a[cand][i]])
                {
                    cand = a[cand][i];
                    ans_r.push_back(cand);
                    used[cand] = true;
                    upd = true;
                    break;
                }
            }
            if(upd) continue;
            break;
        }
    }
    cout << ans_l.size() + 1 + ans_r.size() << endl;
    for(int i = 0; i < ans_l.size(); i++)
    {
        cout << ans_l[ans_l.size()-1-i] << " ";
    }
    cout << s;
    for(int i = 0; i < ans_r.size(); i++)
    {
        cout << " " << ans_r[i];
    }
    cout << endl;
}
