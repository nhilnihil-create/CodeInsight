#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n, a, b, c, q, k, x, y;
    pair<int, int> p;
    queue<int> u;
    cin >> n;
    vector<vector<pair<int, int>>> d(n+1);
    vector<long long> e(n+1, -1);
    for(int i = 0; i < n-1; i++) {
        scanf("%d%d%d", &a, &b, &c);
        d[a].push_back(make_pair(b, c));
        d[b].push_back(make_pair(a, c));
    }
    cin >> q >> k;
    u.push(k);
    e[k] = 0;
    while(u.empty() == false) {
        for(int i = 0; i < d[u.front()].size(); i++) {
            p = d[u.front()][i];
            if(e[p.first] == -1) {
                u.push(p.first);
                e[p.first] = e[u.front()] + p.second;
            }
        }
        u.pop();
    }
    for(int i = 0; i < q; i++) {
        scanf("%d%d", &x, &y);
        printf("%lld\n", e[x] + e[y]);
    }
    return 0;
}