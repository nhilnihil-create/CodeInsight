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
#define MAX_N 200005
vi G[MAX_N];
int v[MAX_N];
int d[MAX_N];
int c[MAX_N];
int ans[MAX_N];
int flag[MAX_N];

struct spl{int v_, d_, c_;};

int main() {
    int n,m,q;
    cin >> n >> m;
    rep(i,m){
        int a,b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    cin >> q;
    rep(i,q){
        cin >> v[i] >> d[i] >> c[i];
    }
    drep(i,q){
        queue<spl> que;
        if(ans[v[i]]==0){
            ans[v[i]] = c[i];
            flag[v[i]] = d[i];
            if(d[i]>0){
                spl s;
                s.v_ = v[i];
                s.d_ = d[i];
                s.c_ = c[i];
                que.push(s);
            }
        }else{
            if(flag[v[i]] < d[i]){
                flag[v[i]] = d[i];
                spl s;
                s.v_ = v[i];
                s.d_ = d[i];
                s.c_ = c[i];
                que.push(s);
            }
        }
        while(que.size()>0){
            spl s = que.front();
            que.pop();
            if(ans[s.v_]==0){
                ans[s.v_] = s.c_;
                flag[s.v_] = s.d_;
                if(s.d_>0){
                    rep(j,G[s.v_].size()){
                        if(flag[G[s.v_][j]]==0 || flag[G[s.v_][j]] < s.d_ - 1){
                            spl s_;
                            s_.c_ = s.c_;
                            s_.v_ = G[s.v_][j];
                            s_.d_ = s.d_ - 1;
                            que.push(s_);
                        }
                    }
                }
            }else{
                flag[s.v_] = max(flag[s.v_], s.d_);
                if(s.d_>0){
                    rep(j,G[s.v_].size()){
                        if(flag[G[s.v_][j]]==0 || flag[G[s.v_][j]] < s.d_ - 1){
                            spl s_;
                            s_.c_ = s.c_;
                            s_.v_ = G[s.v_][j];
                            s_.d_ = s.d_ - 1;
                            que.push(s_);
                        }
                    }
                }
            }
        }
    }

    srep(i,1,n+1){
        cout << ans[i] << endl;
    }

    
    return 0;
}
 
 
