#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200100;

using namespace std;

int n;
long long a[N];
vector < int > v[N];

void dfs(int x, int p)
{
        if(v[x].size() == 1){
                return;
        }
        long long X = 0, mx = 0;
        for(int y: v[x]){
                if(y == p){
                        continue;
                }
                dfs(y, x);
                X += a[y];
                mx = max(mx, a[y]);
        }
        long long A = 2 * a[x] - X;
        if(A < 0 || A > X || (X - A) % 2 || X - mx < (X - A) / 2){
                cout << "NO" << "\n";
                exit(0);
        }
        a[x] = A;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        for(int i = 1, x, y; i < n; i++){
                cin >> x >> y;
                v[x].push_back(y);
                v[y].push_back(x);
        }
        if(n == 2){
                cout << (a[1] == a[2] ? "YES" : "NO") << "\n";
                return 0;
        }
        int r = 1;
        while(v[r].size() == 1){
                r += 1;
        }
        dfs(r, r);
        if(a[r]){
                cout << "NO" << "\n";
                return 0;
        }

        cout << "YES" << "\n";
}
