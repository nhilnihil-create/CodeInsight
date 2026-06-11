#include<bits/stdc++.h>
using namespace std;

int over, just;
vector<int> E[2020];

void dfs(int pv, int v, int k)
{
    if (k == 1) just++;
    if (k <= 0) over++;
    for (int nv : E[v])
        if (nv != pv) dfs(v, nv, k-2);
}

int main()
{
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    
    int ans = -1;
    for (int i = 0; i < N ; i++)
    {
        over = 0;
        vector<int> jvec;
        for (int j : E[i])
        {
            just = 0;
            dfs(i, j, K);
            jvec.push_back(just);
        }
        sort(jvec.begin(), jvec.end());
        for (int jj : jvec) over += jj;
        over -= jvec[E[i].size() - 1];

        if (ans == -1) 
            ans = over;
        else
            ans = min(ans, over);
    }
    cout << ans << endl;
    return 0;
}