#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
#define INF 100000000
#define MAX 100001
//#define int ll
#define ll long long
#define ld long double
#define vi vector<int>
#define pa pair<ll, ll>
#define pb push_back
#define mp make_pair
 
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest&...rest) { cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC(type, c, n) vector<type> c(n);for(auto& i:c)cin>>i;
#define MAT(type, c, m, n) vector<vector<type>> c(m, vector<type>(n));for(auto& r:c)for(auto& i:r)cin>>i;
 
#define BR cout << "\n";
#define SP cout << " ";
#define ENDL cout<<endl;
#define OUT(d) cout<<(d);
#define OUTL(d) cout<<(d)<< "\n";
#define YES OUTL("YES")
#define Yes OUTL("Yes")
#define NO OUTL("NO")
#define No OUTL("No")
#define RET return 0;
 
#define REP(i, n) for(int i=0;i<(n);i++)
#define RREP(i, n) for(int i=n-1;i>=0;--i)
#define FOR(i, m, n) for(int i = m;i < n; i++)
#define RFOR(i, a, b) for(int i=(a)-1;i>=(b);--i)
#define AREP(a, n) for(auto (a):(n))
#define ALL(a) (a).begin(),(a).end()
#define IN(n, a, b) ((a)<=(n)&&(n)<(b))

vi G[100000];
int D1[100000], DN[100000];

void dfs(int* a, int pos, int d){
    if(a[pos] != 0 && a[pos] < d) return;
    a[pos] = d;
    AREP(i, G[pos]) dfs(a, i, d+1);
}

signed main(){ INIT;
    VAR(int, n);
    REP(i, n-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(D1, 0, 1);
    dfs(DN, n-1, 1);
    int cnt = 0;
    REP(i, n) cnt += D1[i] <= DN[i];

    if(cnt > n - cnt) {
        OUTL("Fennec");
    } else {
        OUTL("Snuke");
    }
RET;}
