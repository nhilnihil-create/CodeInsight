#include <bits/stdc++.h> 

using namespace std;

#define fcout(d) cout << fixed << setprecision(d)
#define repU(i,s,t) for(int i = (s); i <= (t); ++i)
#define repD(i,t,s) for(int i = (t); i >= (s); --i)
#define rep(i,n) repU(i,0,n - 1)
#define rep1(i,n) repU(i,1,n)
#define all(v) begin(v),end(v)
#define l_bnd lower_bound
#define u_bnd upper_bound
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back
#define mkp make_pair
#define mkt make_tuple
#define fir first
#define sec second
#define q_ceil(n,d) ((n - 1) / (d) + 1)
#define parity(a,b) (((a)^(b)) & 1 ^ 1)

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int,int> pii;

const pair<int,int> DIR[] = { {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1} };
const int INF_32 = (1 << 30) - 1;
const ll INF_64 = (1LL << 62) - 1;
const int MOD = 1e9 + 7;

ull nxt_sbset(ull s){
	ull tmp = s + (s & -s);
	ull btm = (~tmp & s) / (s & -s) >> 1;
	return btm | tmp;
}

int n,k,a[5000];

bool judge(int idx){
	bitset<5001> bts;
	bts.set(0);
	int i = 0;
	while(i < n && a[i] < k) if(idx != i) bts |= bts << a[i++]; else ++i;
	repU(j,max(0,k - a[idx]),k - 1) if(bts[j]) return 0;
	return 1;
} 

int srch(){
	int l = 0,u = n;
	while(u - l > 1){
		int m = (u + l) / 2;
		if(judge(m)) l = m;
		else u = m;
	}
	if(l) return l;
	return judge(0) - 1;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> k;
	rep(i,n) cin >> a[i];
	sort(a,a + n);
	cout << 1 + srch() << endl;
}



