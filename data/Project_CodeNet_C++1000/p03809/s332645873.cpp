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
#define yn {puts("YES");}else{puts("NO");}
#define MAX_N 200005
vi G[MAX_N];
vi G_[MAX_N];
ll a[MAX_N];
int f[MAX_N];

ll dfs(int x){
    if(G[x].size()==0){
        return a[x];
    }else{
        ll ma = 0;
        ll sum = 0;
        rep(i,G[x].size()){
            ll tmp = dfs(G[x][i]);
            if(tmp == -1){
                return -1;
            }
            ma = max(tmp,ma);
            sum += tmp;
        }
        if(a[x] < ma){
            return -1;
        }
        if(a[x]*2 < sum){
            return -1;
        }
        if(sum < a[x]){
            return -1;
        }
        
        a[x] = 2*a[x] - sum;
        return a[x];
    }
}

int main() {
    int n;
    cin >> n;

    srep(i,1,n+1)cin >> a[i];

    rep(i,n-1){
        int x,y; cin >> x >> y;
        G_[x].push_back(y);
        G_[y].push_back(x);
    }

    // 親が葉の根付き木にする
    int root = 0;
    rep(i,n+1){
        if(G_[i].size()==1){
            root = i;
            break;
        }
    }

    queue<int> que;
    que.push(root);
    f[root] = 1;
    while(que.size()>0){
        int z = que.front();
        que.pop();
        f[z] = 1;
        rep(i,G_[z].size()){
            if(f[G_[z][i]] == 0){
                G[z].push_back(G_[z][i]);
                que.push(G_[z][i]);
            }
        }
    }

    ll ans = a[root];

    ll flag = dfs(root);

   

    if(flag == ans)yn;

    return 0;
}
 

