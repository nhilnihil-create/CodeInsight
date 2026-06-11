/*input
AAAAABBBBAAABBBBAAAA
BBBBAAABBBBBBAAAAABB
10
2 15 2 13
2 13 6 16
1 13 2 20
4 20 3 20
1 18 9 19
2 14 1 11
3 20 3 15
6 16 1 17
4 18 8 20
7 20 3 14
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long 
#define double long double
#define f first
#define s second
#define mp make_pair
#define pb push_back

#define RE(i,n) for (int i = 1; i <= n; i++)
#define RED(i,n) for (int i = n; i > 0; i--)
#define REPS(i,n) for(int i = 1; (i*i) <= n; i++)
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)

#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int INF = 1e18+1;
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;

int raise(int a,int n,int m = MOD){
  if(n == 0)return 1;
  if(n == 1)return a;
  int x = 1;
    x *= raise(a,n/2,m);
    x %= m;
    x *= x;
    x %= m;
    if(n%2)x*= a;
    x %= m;
    return x;
}

int floor1(int n,int k){
    if(n%k == 0 || n >= 0)return n/k;
    return (n/k)-1;
}

int ceil1(int n,int k){
    return floor1(n+k-1,k);
}

const int N = 1e5+1;
int pref[N];
int pref1[N];
string s,t;
int n,m,q;

void solve(){
  	cin >> s >> t >> q;
  	n = s.size();
  	m = t.size();
  	pref[0] = pref1[0] = 0;
  	RE(i,n){
  		pref[i] = pref[i-1]+(s[i-1] == 'A');
  	}
  	RE(i,m){
  		pref1[i] = pref1[i-1]+(t[i-1] == 'A');
  	}
  	while(q--){
  		int a,b,c,d;cin >> a >> b >> c >> d;
  		int a1 = pref[b]-pref[a-1];
  		int a2 = pref1[d]-pref1[c-1];
  		int b1 = (b-a+1)-a1;
  		int b2 = (d-c+1)-a2;
  		int one = a1-a2;
  		int two = b1-b2;
  		one %= 3;
  		two %= 3;
  		if(one < 0)one += 3;
  		if(two < 0)two += 3;
  		if(one == two){
  			cout << "YES";
  		}
  		else cout << "NO";
  		cout << endl;
  	}
}

signed main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  //freopen(".in","r",stdin);freopen(".out","w",stdout);
  int t = 1;
  //cin >> t;
  while(t--){
    solve();
  }
  return 0;
}