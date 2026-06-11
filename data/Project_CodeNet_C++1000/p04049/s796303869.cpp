#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define sz size
#define se second
#define fe first
#define mper make_pair
#define all(x) x.begin(), x.end()
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
using namespace std;


const int INF = 1e8;

int n, k, dis[2010][2010];
vector < int > g[2010];

bool used[2010][2010], check;

vector < pair <int, int> > pos_ans;

void dfs(int orig, int v, int ct = 0) {

    used[orig][v] = 1;

    if(ct > k) {check = 1; return;}

    if(orig != v) {

        dis[orig][v] = ct;

        if(ct == k) {pos_ans.pb(mper(orig, v));}


    }




    for(auto to : g[v]) {

        if(!used[orig][to]) {

            dfs(orig, to, ct + 1);

        }

    }

}

int main(){



cin >> n >> k;



for(int i = 1, l, r; i < n; ++i) {

    cin >> l >> r;

    g[l].pb(r);
    g[r].pb(l);

}

for(int i = 1; i <= n; ++i) {
    dfs(i, i);
}


if(!check) {cout << 0;return 0;}


int ans = (int)1e8;

for(auto to : pos_ans) {

    int a = to.fe;
    int b = to.se;
    int ct = 0;



    for(int i = 1; i <= n; ++i) {

        if(i == a || b == i) {continue;}

        if(dis[a][i] == 0) {ct++;}
        else if(dis[b][i] == 0) {ct++;}

    }

    ans = min(ans, ct);

}

cout << ans;

return 0;
}

/*

2000 2


*/
