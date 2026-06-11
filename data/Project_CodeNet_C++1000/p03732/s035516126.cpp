#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N, W; cin >> N >> W;
    vector<vector<ll>> a(4);
    ll w0;
    for (int i = 0; i < N; i++)
    {
        ll w, v; cin >> w >> v;
        if(i==0) w0 = w;
        if(w==w0)        a[0].push_back(v);
        else if(w==w0+1) a[1].push_back(v);
        else if(w==w0+2) a[2].push_back(v);
        else if(w==w0+3) a[3].push_back(v);
    }
    for(auto &i : a){
        i.push_back(0);
        sort(i.begin(),i.end(), greater<int>());
    }

    for (auto &i : a)
    {
        ll prev;
        for (int j = 1; j < i.size(); j++)
        {
            i[j] = i[j] + i[j-1];
        }
    }
    
    ll ans = 0;
    for (int i = 0, n=a[0].size(); i <n ; i++)
    {
        for (int j = 0, m=a[1].size(); j < m; j++)
        {
            for (int k = 0, p=a[2].size(); k < p; k++)
            {
                for (int l = 0, q=a[3].size(); l < q; l++)
                {
                    if(w0 * i + (w0+1) * j + (w0+2) * k + (w0+3) * l > W) continue;
                    ll tmp = 0;
                    if(i>0) tmp += a[0][i-1];
                    if(j>0) tmp += a[1][j-1];
                    if(k>0) tmp += a[2][k-1];
                    if(l>0) tmp += a[3][l-1];
                    ans = max(ans, tmp);
                }
            }
        }
    }
    cout << ans << endl;
}