#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, ans, sum;
ll A[MAXN];
int fen[MAXN];
vector<ll> comp;

void add(int pos){
	for (; pos<MAXN; pos+=pos&-pos) fen[pos]++;
}
int get(int pos){
	int res=0;
	for (; pos; pos-=pos&-pos) res+=fen[pos];
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>k;
	for (int i=1; i<=n; i++){
		cin>>x;
		sum+=x;
		A[i]=sum-i*k;
	}
	for (int i=0; i<=n; i++) comp.pb(A[i]);
	sort(all(comp));
	comp.resize(unique(all(comp))-comp.begin());
	
	for (int i=0; i<=n; i++) A[i]=lower_bound(all(comp), A[i])-comp.begin()+1;
	
	for (int i=0; i<=n; i++){
		ans+=get(A[i]);
		add(A[i]);
	}
	cout<<ans<<'\n';
	
	return 0;
}
