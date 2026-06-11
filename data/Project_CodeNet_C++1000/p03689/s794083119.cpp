#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    ll H, W, h, w;
    cin >> H >> W >> h >> w;
    int count = 0;
    for(int i = h; i <= H; i += h)
    {
        for(int j = w; j <= W; j += w)
        {
            count++;
        }
    }
    ll co = (1e9 - 1) / (h*w-1);
    ll ans = count * (-h*w*co+co-1) + co*(H*W-count);
    if(ans < 0) cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
        vector<vector<int>> tmp(H+1, vector<int>(W+1));
        for(int i = 1; i <= H; i++)
        {
            int x = i;
            for(int j = 1; j <= W; j++)
            {
                if(i % h != 0)
                {
                    cout << co << " ";
                }
                else
                {
                    if(j % w != 0) cout << co << " ";
                    else cout << -h*w*co+co-1 << " ";
                }
            }
            cout << endl;
        }
    }
}

