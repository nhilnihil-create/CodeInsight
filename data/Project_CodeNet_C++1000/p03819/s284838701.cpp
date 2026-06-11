#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <functional>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <list>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const ll INF = 1LL<<29;
const ll mod = 1e9+7;
#define rep(i,n) for(int (i)=0;(i)<(ll)(n);++(i))
#define repd(i,n,d) for(ll (i)=0;(i)<(ll)(n);(i)+=(d))
#define all(v) (v).begin(), (v).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset((m),(v),sizeof(m))
#define chmin(X,Y) ((X)>(Y)?X=(Y),true:false)
#define chmax(X,Y) ((X)<(Y)?X=(Y),true:false)
#define fst first
#define snd second
#define UNIQUE(x) (x).erase(unique(all(x)),(x).end())
template<class T> ostream &operator<<(ostream &os, const vector<T> &v){int n=v.size();rep(i,n)os<<v[i]<<(i==n-1?"":" ");return os;}
#define B 330
#define N 100010
ll res[N], s[N];
int main(){
	int n, m;
	cin>>n>>m;
	rep(i, n){
		int l, r;
		cin>>l>>r;
		int mn = INF;
		for(int j = 1; j < B; j++){
			int a = (l+j-1)/j, b = r/j;
			if(a<=b){
				res[j]++;
				b = min(b, mn-1);
				a = max(a, B);
				if(a<=b){
					s[a]++;
					s[b+1]--;
					mn = min(mn, a);
				}
			}
		}
	}
	rep(i, N-1) s[i+1] += s[i];
	rep(i, N) res[i] += s[i];
	rep(i, m) cout<<res[i+1]<<endl;
	return 0;
}
