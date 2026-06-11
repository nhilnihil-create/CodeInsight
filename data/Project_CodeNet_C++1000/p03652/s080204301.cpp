#include<iostream>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
    int n,m;scanf("%d %d",&n,&m);
    vector<bool> used(m,true);
    vector<queue<int>> Q(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int x;scanf("%d",&x);
            Q[i].push(--x);
        }
    }
    int ans = n;
    for (int i = 0; i < m; ++i)
    {
        if(i){
            for (int j = 0; j < n; ++j)
            {
                while(!used[Q[j].front()])Q[j].pop();
            }
        }

        vector<int> cnt(m,0);
        for (int j = 0; j < n; ++j)
        {
            cnt[Q[j].front()]++;
        }
        int mx=0,id=0;
        for (int j = 0; j < m; ++j)
        {
            if(cnt[j] > mx)mx = cnt[j],id = j;
        }
        ans = min(ans,mx);
        used[id] = false;
    }
    printf("%d\n", ans);
    return 0;
}