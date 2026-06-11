#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int dx[9] = {-2, -2, -2, -1, -1, -1, 0, 0, 0};
int dy[9] = {-2, -1,  0, -2, -1,  0,-2,-1, 0};
LL res[10];
int H,W,N;

map<pair<int,int>, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin >> H >> W >> N;
    res[0] = (LL)(H-2)*(LL)(W-2);
    int u,v,tx,ty;
    for(int i = 0; i < N; ++i)
    {
        cin >> u >> v;
        for(int k = 0; k < 9; ++k)
        {
            tx = u + dx[k];
            ty = v + dy[k];
            if(tx < 1 || ty < 1 || tx > H-2 || ty > W-2) continue;
            mp[make_pair(tx,ty)]++;
        }
    }

    for(pair<pair<int,int>,int> pa : mp)
    {
        --res[0];
        ++res[pa.second];
    }
    for(int i = 0; i <= 9; ++i)
        cout << res[i] <<endl;
    return 0;
}
