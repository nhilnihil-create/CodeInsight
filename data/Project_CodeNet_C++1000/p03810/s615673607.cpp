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
#define sar(a,n) cout<<#a<<":";rep(kbrni,n)cout<<" "<<a[kbrni];cout<<endl
#define svec(v) cout<<#v<<":";rep(kbrni,v.size())cout<<" "<<v[kbrni];cout<<endl
#define svecp(v) cout<<#v<<":";each(kbrni,v)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(kbrni,s)cout<<" "<<kbrni;cout<<endl
#define smap(m) cout<<#m<<":";each(kbrni,m)cout<<" {"<<kbrni.first<<":"<<kbrni.second<<"}";cout<<endl

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

ll gcd(ll a,ll b)
{
    if(a == 0 || b == 0){
        return max(a,b);
    }
    if(a % b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

void Show(int flag)
{
	if(flag){
		cout << "First\n";
	}else{
		cout << "Second\n";
	}
}

vi solve(vi& a,int hoge)
{
	int n = len(a);
	int id = -1;
	int cnt = 0;
	rep(i,n){
		if(a[i] % 2 == 0){
			cnt++;
		}else{
			id = i;
		}
	}
	if(cnt % 2 == 0){
		if(n - cnt > 1){
			Show(hoge^0);
			return {-1};
		}else{
			if(a[id] == 1){
				Show(hoge^0);
				return {-1};
			}
			a[id]--;
			ll g = 0;
			rep(i,n){
				g = gcd(g,a[i]);
			}
			rep(i,n){
				a[i] /= g;
			}
			return a;
		}
	}else{
		Show(hoge^1);
		return {-1};
	}
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
	vi a(n);
	rep(i,n){
		cin >> a[i];
	}
	int hoge = 0;
	while(1){
		a = solve(a,hoge);
		hoge ^= 1;
		if(a[0] == -1){
			break;
		}
	}
    return 0;
}
