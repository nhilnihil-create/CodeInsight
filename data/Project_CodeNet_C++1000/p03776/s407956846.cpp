//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
 
const long long MOD = 998244353;
const long long mod = 1000000007;
const long long INF = 10000000000000;
 
#define itn int
#define endl "\n"
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
 
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//最頻値とランレングス圧縮
template<class T>
vector<pair<T,int>> runlength(vector<T> arr) {
	int i = 0;
	int n = arr.size();
	vector<pair<T, int>> run;
	while (i < arr.size()) {
		T t = arr[i];
		int k = 0;
		while (i + k < n && arr[i + k] == t) k++;
		run.push_back(pair<T, int>(t, k));
		i += k;
	}
	return run;
}
#define MAXN 60
ll C[MAXN][MAXN];
void comb_table(int MAX_N){
	rep(i,MAX_N)rep(j,MAX_N) C[i][j] = (j==0||j==i ? 1LL : C[i-1][j-1]+C[i-1][j]);
}
int main(void){
   int n,a,b;cin >> n >> a >> b;
   vector<ll> d(n);
   rep(i,n)cin >> d[i];
   sort(all(d)); reverse(all(d));
   
   ll sum = 0LL;
   rep(i,a) sum += d[i];
   cout << fixed << setprecision(22) << (double)sum / (double)a << endl;
   
   auto run = runlength(d);
   comb_table(60);
   //一種類だけなら
   int ub;
   int left;
   ll ans = 0LL;
   if(run[0].second >= a){
      left = run[0].second;
      if(run[0].second <= b) ub = run[0].second;
      else ub = b;
      
      for(int j = a;j <= ub;j++) ans += C[left][j];
   }else{
      int count = 0;
      for(auto i : run){
         if(count + i.second < a) count += i.second;
         else{ ans = C[i.second][a - count]; break;}
      }
   }
   cout << ans << endl;
   return 0;
}
