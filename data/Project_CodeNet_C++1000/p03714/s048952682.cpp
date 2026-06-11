#include"bits/stdc++.h"
#define int long long
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define itr(i,x) for(auto i=(x).begin();i!=(x).end();++i)
#define All(x) (x).begin(),(x).end()
#define gridif(a,x,b) if((a)<=(x)&&(x)<(b))

using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
const int mod=1000000007;

int digitsum(int n,int b){
	if(b<2) return -1;
	if(n<b) return n;
	return digitsum(n/b,b)+n%b;
}
int mpow(int a,int x);
int m_inv(int n);
vector<int> split(int n,int a);
string xal_number(int n,int x);
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}
class Factorial{
private:
	vector<int> fac;
public:
	Factorial(int N){
		fac.push_back(1);
		rep(i,N) fac.push_back(fac[i]*(i+1)%mod);
	}
	int fact(int a){return fac[a];}
	int ifac(int a){return m_inv(fac[a]);}
	int cmb(int n,int r);
};
struct UnionFind {
    vector<int> par; // 親ノード
    UnionFind(int n = 1) { init(n);}
    void init(int n = 1) {
        par.resize(n);
        rep(i,n) par[i] = -1;
    }
    int root(int x) {
        if (par[x] <0) return x;
        else return par[x] = root(par[x]);      
    }
    int size(int x){ return -par[root(x)];}
    bool issame(int x, int y) {return root(x)==root(y);}
    bool connect(int x, int y);
};

signed main(){
	int N;
	cin>>N;
	vector<int> a(3*N),S0(N+1,0),S1(N+1,0);
	rep(i,N*3) cin>>a[i];
	multiset<int> st1,st2;
	int S=0;
	rep(i,N){ 
		st1.insert(a[i]);
		S0[0]+=a[i];
		st2.insert(a[3*N-1-i]);
		S1[0]+=a[3*N-1-i];
	}
	//cout<<S0[0]<<" "<<S1[0]<<endl;
	rep(i,N){
		st1.insert(a[i+N]);
		S0[i+1]=S0[i]+a[i+N]-*st1.begin();
		st1.erase(st1.begin());
		auto it=st2.end();it--;
		st2.insert(a[2*N-1-i]);
		S1[i+1]=S1[i]+a[2*N-1-i]-*it;
		st2.erase(it);
	}
	int ans=-LLONG_MAX;
	rep(i,N+1){ 
		ans=max(S0[i]-S1[N-i],ans);
		//cout<<S0[i]<<" "<<S1[N-i]<<endl;
	}
	cout<<ans<<endl;
}