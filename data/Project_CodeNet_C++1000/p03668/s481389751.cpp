#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(a, b) for(auto (a): (b))
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define pb push_back
#define show(x) cout <<#x<<" = "<<(x)<<endl
#define spair(p) cout <<#p<<": "<<p.fi<<" "<<p.se<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout <<" "<<kbrni;cout<<endl

using namespace std;

typedef pair<int,int>P;

const int MAX_N = 100005;

vector<int> G[MAX_N];
bool flag[MAX_N];

int dfs(int u)
{
    flag[u] = true;
    int ans = 0;
    rep(i,G[u].size()){
        if(!flag[G[u][i]]){
            ans ^= (dfs(G[u][i]) + 1);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }
    rep(i,n){
        flag[i] = false;;
    }
    int res = dfs(0);
    if(res){
        cout << "Alice\n";
    }else{
        cout << "Bob\n";
    }
    return 0;
}
