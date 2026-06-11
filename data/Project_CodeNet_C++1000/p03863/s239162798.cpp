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
class UnionFind{
private:
	vector<int> Parent;
public:
	UnionFind(int N){rep(i,N) Parent.push_back(-1);}
	int root(int A){
		if(Parent[A]<0) return A;
		else return root(Parent[A]);
	}
	int size(int A){return -Parent[root(A)];}
	bool connect(int A,int B);
};

signed main(){
    string s;
    cin>>s;
    int ans;
    ans =s.size()%2;
    if(s[0]!=s.back()) ans=1-ans;
    if(ans==0) cout<<"First"<<endl;
    if(ans==1) cout<<"Second"<<endl;
}
