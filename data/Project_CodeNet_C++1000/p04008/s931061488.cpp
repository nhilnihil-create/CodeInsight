#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a);
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define per(i,a,b) for(int i = a; i >= b; i--)
#define __ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
typedef double db;
const int N = 1e5+100;
const db EPS = 1e-9;
using namespace std;

void dbg() {cout << "\n";}
template<typename T, typename... A> void dbg(T a, A... x) {cout << a << ' '; dbg(x...);}
#define logs(x...) {cout << #x << " -> "; dbg(x);}

int n,k,a[N],ans,rem[N];
vector<int> G[N];

void dfs(int x){
    rem[x] = 1;
    for(auto &y:G[x]){
        dfs(y);
        if(rem[y] == k && a[y] != 1) ans++, rem[y] = 0;
        rem[x] = max(rem[x],rem[y]+1);
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d",&a[i]);
    if(a[1] != 1) a[1] = 1, ans++;
    rep(i,2,n) G[a[i]].push_back(i);
    dfs(1);
    printf("%d\n",ans);
    return 0;
}