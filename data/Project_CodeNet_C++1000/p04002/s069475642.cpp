#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N = 1e5 + 5, M = 4 * N + 5;

map<pair<int, int>, bool> vis;
map<pair<int, int>, int> cnt;

int getSum(int x, int y){
    int ret = 0;

    for(int i = x ; i <= x + 2 ; ++i)
        for(int j = y ; j <= y + 2 ; ++j)
            ret += (vis.find(make_pair(i, j)) != vis.end());

    return ret;
}

int n, m;

ll out[10];

bool isOut(int x, int y){
    return (x <= 0 || y <= 0 || x + 2 > n || y + 2 > m);
}

void solve(int x, int y){
    for(int i = 0 ; i < 3 ; ++i)
        for(int j = 0 ; j < 3 ; ++j)
            if(!isOut(x - i, y - j))
                cnt[make_pair(x - i, y - j)] = getSum(x - i, y - j);
}

int main(){
    int h;
    scanf("%d %d %d", &n, &m, &h);
    vector<pair<int, int> > points;
    while(h--){
        int x, y;
        scanf("%d %d", &x, &y);
        vis[make_pair(x, y)] = true;
        points.emplace_back(x, y);
    }

    for(auto p : points)
        solve(p.first, p.second);


    out[0] = (1ll * n - 2) * (1ll * m - 2);

    for(auto p : cnt)
        ++out[p.second], --out[0];


    for(int i = 0 ; i <= 9 ; ++i)
        printf("%lld\n", out[i]);

}