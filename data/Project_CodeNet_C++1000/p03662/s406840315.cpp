#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> graph[1000000];
int dist[2][1000000];
int main()
{
    int n;
    cin >> n;

    rep(i, 0, n - 1)
    {
        int a, b;
        cin >> a >> b;
        --a, --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    rep(c, 0, 2)
    {
        queue<pii> que;
        int start = (c == 0)? 0: n - 1;
        que.push(make_pair(start, 1));
        while(que.size() > 0)
        {
            int now, d;
            tie(now, d) = que.front();
            que.pop();

            if (dist[c][now] > 0) continue;
            dist[c][now] = d;
            
            for (auto next: graph[now])
                que.push(make_pair(next, d + 1));
        }
    }
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    rep(i, 0, n)
    {
        if (dist[0][i] <= dist[1][i])
            ++cnt1;
        else
            ++cnt2;
        
        // cout << i << ' ' << dist[0][i] << ' ' << dist[1][i] << endl;
    }
    if (cnt1 > cnt2)
        cout << "Fennec" << endl;
    else
        cout << "Snuke" << endl;
    // cout << cnt1 << ' ' << cnt2 << endl;
    return 0;
}