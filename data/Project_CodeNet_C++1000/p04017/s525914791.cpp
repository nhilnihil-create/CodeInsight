#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

const ll MOD=1000000007;
int N;
ll L,Q;
int nex[17][100010];
int check(int u, int x){
    rep(k,0,17){
        if(u>>k&1){
            x=nex[k][x];
        }
    }
    return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    vector<ll> x(N,0);
    rep(i,0,N) cin>>x[i];
    cin>>L>>Q;
    rep(i,0,N){
        nex[0][i]=ub(x,x[i]+L)-1-x.begin();
    }
    rep(k,0,16){
        rep(v,0,N){
            if(nex[k][v]==N-1) nex[k+1][v]=N-1;
            else nex[k+1][v]=nex[k][nex[k][v]];
        }
    }
    rep(w,0,Q){
        int a,b;
        cin>>a>>b;
        a--; b--;
        if(a>b) swap(a,b);
        int ok=N-1, ng=0;
        while(ok-ng>1){
            int mid=(ok+ng)/2;
            if(check(mid, a)>=b) ok=mid;
            else ng=mid;
        }
        cout <<ok<<"\n";
    }
}