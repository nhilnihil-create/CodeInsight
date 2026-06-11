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

const int MAX_N = 1000005;

int f[MAX_N];
int sm[MAX_N];

ll add(ll x,ll y)
{
    return (x + y)%MOD;
}

ll sub(ll x,ll y)
{
    return (x+MOD-y)%MOD;
}

ll mul(ll x,ll y)
{
    return x*y%MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n;
	cin >> n;
	f[0] = 0, f[1] = n;
	sm[0] = 0, sm[1] = f[1];
	srep(i,2,n+1){
		f[i] = sub(add(sub(sm[i-1],sm[max(i-n-2,0)]),add(max(n-i+2,0),mul(n-1,n-1))),f[i-2]);
		if(i == 2) f[i] = sub(f[i],1);
		sm[i] = add(sm[i-1],f[i]);
	}
	cout << f[n] << "\n";
    return 0;
}
