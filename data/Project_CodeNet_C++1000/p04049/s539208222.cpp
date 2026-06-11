#include <bits/stdc++.h>
#define sz size
#define pb push_back
#define mper make_pair
#define PI 3.14159
#define fe first
#define se second
#define ll long long
//#define forik(i, a, b) for(ll i = a; i <= b; ++i)
//#define vl vector<ll>
//#define pll pair<ll, ll>
#define mal ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define saken stringusing namespace std;
using namespace std;

int n, k, dis[2010][2010], mx;
vector < int > g[2010];

bool used[2010][2010];

bitset <2010> t[2100];

vector < pair <int, int> > pos_ans;

void dfs(int orig, int v, int ct = 0) {

    used[orig][v] = 1;

    for(auto to : g[v]) {

        if(!used[orig][to]) {

            dis[orig][to] = ct + 1;

            t[orig][to] = (dis[orig][to] > k);

            mx = max(mx, ct + 1);



            if(ct + 1 == k) {pos_ans.pb(mper(orig, to));}


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


if(mx <= k) {cout << 0;return 0;}


int ans = (int)1e8;

for(auto to : pos_ans) {

    int a = to.fe;
    int b = to.se;

    int ct = (t[a] | t[b]).count();


    ans = min(ans, ct);

}

cout << ans;

return 0;
}
