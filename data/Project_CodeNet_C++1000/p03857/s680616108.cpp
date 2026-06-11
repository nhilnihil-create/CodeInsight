#include "bits/stdc++.h"
#define Rep(i,n) for(int i=0;i<n;i++)
#define For(i,n1,n2) for(int i=n1;i<n2;i++)
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define put(a) cout<<a<<endl;
#define all(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define TDARRAY(int,a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) {if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a, T b) {if(a>b){a=b;return 1;}return 0;}

int n,k,l;
void init(vector<int>& par,vector<int>& height,int n){
    REP(i,n){
        par[i]  = i;
        height[i] = 0;
    }
}
int root(vector<int>& par,vector<int>& height,int x){
    if(par[x]==x){
        return x;
    }else{
        par[x] = root(par,height,par[x]);
        return par[x];
    }
}
bool same(vector<int>& par,vector<int>& height,int x,int y){
    return root(par,height,x)==root(par,height,y);
}
void unite(vector<int>& par,vector<int>& height,int x,int y){
    x = root(par,height,x);
    y = root(par,height,y);
    if(x==y)return;
    if(height[x]<height[y]){
        par[x]=y;
    }else{
        par[y]=x;
        if(height[x]==height[y])height[x]++;
    }
}
int main(){
    cin >> n >> k >> l;
    vector<int> p(k);
    vector<int> q(k);
    REP(i,k){
        int _p,_q;
        cin >> _p >> _q;
        p[i] = _p-1;
        q[i] = _q-1;
    }
    vector<int> r(l);
    vector<int> s(l);
    REP(i,l){
        int _r,_s;
        cin >> _r >> _s;
        r[i] = _r-1;
        s[i] = _s-1;
    }
    
    vector<int> par(n);
    vector<int> height(n);
    vector<int> par2(n);
    vector<int> height2(n);
    
    init(par,height,n);
    init(par2,height2,n);
    
    REP(i,k){
        unite(par,height,p[i],q[i]);
    }
    REP(i,l){
        unite(par2,height2,r[i],s[i]);
    }
    
    vector<pair<P,int>> pr(n);
    Rep(i,n){
        pr[i] = make_pair(make_pair(root(par,height,i), root(par2,height2,i)),i);
    }
    SORT(pr);
    
    vector<int> res(n,0);
    
    int con = 1;
    REP(i,n-1){
        if(pr[i].first==pr[i+1].first){
            con++;
        }else{
            REP(j,con){
                res[pr[i-j].second]+=con;
            }
            con=1;
        }
    }
    REP(j,con){
        res[pr[n-1-j].second]+=con;
    }
    
    REP(i,n){
        put(res[i]);
    }
    return 0;
}

