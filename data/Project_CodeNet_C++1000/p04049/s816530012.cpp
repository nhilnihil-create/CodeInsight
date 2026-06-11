#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 2020;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int d[N];
vector < int > v[N];

void bfs(int x, int y)
{
        for(int i = 1; i <= n; i++){
                d[i] = n + 1;
        }
        d[x] = d[y] = 0;
        queue < int > q;
        q.push(x);
        q.push(y);
        while(!q.empty()){
                x = q.front();
                q.pop();
                for(int y: v[x]){
                        if(d[x] + 1 < d[y]){
                                d[y] = d[x] + 1;
                                q.push(y);
                        }
                }
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int k;
        cin >> n >> k;
        for(int i = 1; i < n; i++){
                int x, y;
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        int res = n;
        for(int i = 1; i <= n; i++){
                for(int j: v[i]){
                        if(k % 2){
                                bfs(i, j);
                        } else{
                                bfs(i, i);
                        }
                        int cnt = 0;
                        for(int j = 1; j <= n; j++){
                                if(d[j] > k / 2){
                                        cnt += 1;
                                }
                        }
                        res = min(res, cnt);
                }
        }
        cout << res << "\n";
}
