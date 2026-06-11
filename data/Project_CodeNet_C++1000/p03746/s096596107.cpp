#include<bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n, m;
int bio[MAXN];
vector <int> v[MAXN];
vector <pair <int, int> > sol;

void dfs (int x, int c, int d) {
    sol.push_back(make_pair(c, x));
    bio[x] = 1;
    for (int i=0; i<v[x].size(); i++) {
        int sus = v[x] [i];
        if (!bio[sus]) {
            dfs(sus, c + d, d);
            break;
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 1, 1);
    dfs(1, -1, -1);
    sort(sol.begin(), sol.end());
    cout << sol.size()-1 << endl;
    for (int i=0; i<sol.size(); i++) {
        if (i+1 < sol.size() && sol[i].second == sol[i+1].second) continue;
        cout << sol[i].second << " ";
    }
    return 0;
}
