#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<" = "<<x<<endl;
#define dbg_v(v,n) {cerr<<#v<<" = [";for(int III=0;III<=n;III++)cerr<<v[III]<<(III!=n?",":"]\n");}
#define ll long long
#define ld long double
#define pii pair<int,int>
#define MOD 1000000007
#define zeros(x) x&(x-1)^x
#define Nmax 500005
using namespace std;

int uz[Nmax], n, m, x, y;
vector<int> ans, v[Nmax];

void dfs(int nod){
    ans.push_back(nod);
    uz[nod] = 1;
    for (auto it : v[nod]){
        if (uz[it]) continue;
        dfs(it);
        return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1;i<=m;i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    reverse(ans.begin(),ans.end());
    ans.pop_back();
    dfs(1);
    cout << ans.size() << '\n';
    for (auto it : ans) cout << it << ' ';
    cout << '\n';

    return 0;
}
