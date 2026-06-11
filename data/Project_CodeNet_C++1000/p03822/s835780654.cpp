#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = INT_MAX / 2; const ll INF = LLONG_MAX / 2;
//template end

vector<int> g[100010];
ll dfs(int v){
    vector<ll> a;
    for(int nxt:g[v])a.push_back(dfs(nxt));
    sort(ALL(a)); reverse(ALL(a)); ll res=0;
    rep(i,0,a.size())chmax(res,a[i]+i+1);
    return res;
}

int main(){
    int n; scanf("%d",&n);
    rep(i,1,n){
        int p; scanf("%d",&p);
        g[p-1].push_back(i);
    }
    printf("%lld\n",dfs(0));
    return 0;
}