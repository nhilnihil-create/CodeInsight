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
const int INF=5000;
int n,ma,mb,x,y,z;
int a[44],b[44],c[44];
int f[44][444][444];
int main () { 
	scanf("%d %d %d",&n,&ma,&mb);
	for(int i=0;i<n;i++)
		for(int j=0;j<402;j++)
			for(int k=0;k<402;k++)
				f[i][j][k]=INF;
	for(int i=0;i<n;i++)
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
	f[0][0][0]=0;
	f[0][a[0]][b[0]]=c[0];
	for(int i=0;i<n-1;i++)
		for(int j=0;j<=10*(i+1);j++)
			for(int k=0;k<=10*(i+1);k++){
				f[i+1][j][k]=min(f[i+1][j][k],f[i][j][k]);
				f[i+1][j+a[i+1]][k+b[i+1]]=min(f[i+1][j+a[i+1]][k+b[i+1]],f[i][j][k]+c[i+1]);
			}
	int ans=INF;
	for(int i=1;i<402;i++)
		for(int j=1;j<402;j++){
			if(ma*j==mb*i)ans=min(ans,f[n-1][i][j]);
		}
	printf("%d\n",(ans==INF)?-1:ans);
}