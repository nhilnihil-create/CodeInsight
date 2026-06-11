#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int W, H, N;
    cin >> W >> H >> N;
    
    vector<vector<bool>> mp(H, vector<bool>(W, true));
    for(int i=0; i<N; i++)
    {
        int x, y, a;
        cin >> x >> y >> a;
        if(a==1)
        {
            for(int j=0; j<x; j++)
            {
                for(int k=0; k<H; k++)
                {
                    mp[k][j] = false;
                }
            }
        }
        if(a==2)
        {
            for(int j=x; j<W; j++)
            {
                for(int k=0; k<H; k++)
                {
                    mp[k][j] = false;
                }
            }
        }
        if(a==3)
        {
            for(int j=0; j<y; j++)
            {
                for(int k=0; k<W; k++)
                {
                    mp[j][k] = false;
                }
            }
        }
        if(a==4)
        {
            for(int j=y; j<H; j++)
            {
                for(int k=0; k<W; k++)
                {
                    mp[j][k] = false;
                }
            }
        }
    }

    int ans = 0;
    for(auto vec : mp)
    {
        for(auto b : vec)
        {
            if(b) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
