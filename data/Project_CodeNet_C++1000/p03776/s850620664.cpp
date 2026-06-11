/* */
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
const int MAX_LEN = 1010;
#define GETLINE(x) fgets(x,MAX_LEN,stdin);
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<double, double> dd;
typedef tuple<int, int, int> iii;
typedef vector<ii> vii;
typedef vector<ll> vll;
#ifdef XVENOM
	#define errp(...) fprintf(stderr, __VA_ARGS__)
	#define dbg(...) errp("[%s]: ", #__VA_ARGS__), dbg_str(__VA_ARGS__)
#else
	#define errp(...)
	#define dbg(...)
#endif
template <typename U, typename V> string to_string (pair<U, V>);
string to_string (const string& e_) { return "\"" + e_ + "\""; }
string to_string (char e_) { return "\'" + string(1, e_) + "\'"; }
string to_string (bool e_) { return e_ ? "true" : "false"; }
template <typename T> string to_string (T e_) {
	string s_ = "[ ";
	for (const auto& x_ : e_) s_ += to_string(x_) + " ";
	return s_ + "]";
}
template <typename U, typename V> string to_string (pair<U, V> e_) {
	return "(" + to_string(e_.first) + ", " + to_string(e_.second) + ")";
}
void dbg_str () { errp(" \n"); }
template <typename U, typename... V> void dbg_str (U u, V... v) {
 	errp(" %s", to_string(u).c_str()); dbg_str(v...);
}
/* --- */
ll n,a,b,ans,sum,k,f;
ll v[55];
ll c[55][55];
void comb(){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++){
			if(i==0 || i==j)c[i][j]=1;
			else c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
}
int main () { 
	scanf("%lld %lld %lld",&n,&a,&b);
	comb();
	for(int i=0;i<n;i++)
		scanf("%lld",&v[i]);
	sort(v,v+n);
	reverse(v,v+n);
	for(int i=0;i<a;i++)sum+=v[i];
	 f=1;
	for(int i=1;i<n;i++)if(v[i]==v[0])f++;
	if(f>=a){
		printf("%Lf\n",(long double)v[a-1]);
		for(int i=a;i<=min(b,f);i++)
			ans+=c[f][i];
		printf("%lld\n",ans);
		return 0;
	}
	printf("%Lf\n",(long double)sum/a);
	f=0,k=0;
	for(int i=0;i<n;i++)if(v[i]==v[a-1]){
		f++;
		if(i<a)k++;
	}
	printf("%lld\n",c[f][k]);
}
