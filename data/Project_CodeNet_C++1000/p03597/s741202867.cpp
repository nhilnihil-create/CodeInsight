#include<bits/stdc++.h>
// Begin Header {{{
#define lli long long int
#define rep(i,n) for(lli i=0; i<n; i++)
#define loop(i, j, n) for(lli i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const double PI = acos(-1);
using namespace std;
using Graph = vector<vector<lli>>;
using P = pair<int, int>;
// }}} End Header
typedef struct {
	lli to;
	lli cost;
}edge;
vector<vector<edge>> G(100010);
vector<lli> dist(100010, 0);
lli K;

int main(){
	int n, a;
	cin >> n >> a;
	cout << n*n-a << endl;
	return 0;
}