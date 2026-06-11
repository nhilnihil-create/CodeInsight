#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100005;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m,n;
    cin >> m >> n;
    vi a(n);
    vi od;
    rep(i,n){
        cin >> a[i];
        if(a[i] % 2){
            od.pb(a[i]);
        }
    }
    vi ans;
    if(len(od) > 2){
        cout << "Impossible\n";
        return 0;
    }else if(len(od) == 2){
        cout << od[0] << " ";
        if(od[0] != 1){
            ans.pb(od[0]-1);
        }
        rep(i,n){
            if(a[i] % 2 == 0){
                cout << a[i] << " ";
                ans.pb(a[i]);
            }
        }
        cout << od[1] << "\n";
        ans.pb(od[1]+1);
    }else if(len(od) == 1){
        cout << od[0] << " ";
        if(od[0] != 1){
            ans.pb(od[0]-1);
        }
        rep(i,n){
            if(a[i] % 2 == 0){
                cout << a[i] << " ";
                ans.pb(a[i]);
            }
        }
        cout << "\n";
        ans.pb(1);
    }else{
        ans.pb(a[0]-1);
        rep(i,n-1){
            ans.pb(a[i+1]);
        }
        ans.pb(1);
        rep(i,n){
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    cout << len(ans) << "\n";
    rep(i,len(ans)){
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}
