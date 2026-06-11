#include<bits/stdc++.h>
using namespace std;
long long ans[10];
int main()
{
    int H, W, N;
    scanf("%d%d%d", &H, &W, &N);
    vector<pair<int, int> > points;
    vector<pair<int, int> > pos;
    for(int i=0; i<N; ++i)
    {
        int x, y; scanf("%d%d", &x, &y);
        --x; --y;
        points.emplace_back(x, y);
        for(int d=-1; d<=1; ++d)
            for(int e=-1; e<=1; ++e)
                pos.emplace_back(x+d, y+e);
    }
    sort(pos.begin(), pos.end());
    sort(points.begin(), points.end());
    pos.resize(unique(pos.begin(), pos.end())-pos.begin());
    ans[0] = 1LL*(H-2)*(W-2);
    for(auto t: pos)
    {
        int x, y; tie(x, y) = t;
        if(x <= 0 || x >= H-1 || y<=0 || y >= W-1) continue;
        ans[0]--;
        int cnt = 0;
        for(int d=x-1; d<=x+1; ++d)
            for(int e=y-1; e<=y+1; ++e)
                if(binary_search(points.begin(), points.end(), make_pair(d,e)))
                    ++cnt;
        ans[cnt]++;
    }
    for(int i=0; i<10; ++i)
        printf("%lld\n", ans[i]);
    return 0;
    
    
    
}