#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 100005
vi v[MAX_N];

int dfs(int x){
    int m = v[x].size();
    if(m==0){
        return 0;
    }

    int tmp[m] = {};

    rep(i,m){
        tmp[i] = dfs(v[x][i]);
    }
    sort(tmp,tmp+m);
    int ret = 0;
    rep(i,m){
        ret = max(ret,m-i+tmp[i]);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    srep(i,2,n+1){
        int a;
        cin >> a;
        v[a].push_back(i);
    }
    
    int ans = dfs(1);
    cout << ans << endl;
    return 0;
}
 
 
