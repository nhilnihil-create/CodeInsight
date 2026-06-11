#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/assoc_container.hpp> 
using namespace std; 
using namespace __gnu_pbds;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define F0R(i,a) for(int i = 0; i < a; i++)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define newl '\n'
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << "\n", 0;
#define bug(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " " << 
 
const ll MOD = 998244353;
const ll INF = 1e9 + 7;

const int MX = 41;
array<int,3> abc[MX];
int N, a[MX], b[MX], c[MX], ma, mb, DP[MX][401][401],prefa[MX],prefb[MX],ans;

//check int vs ll and precision
//check logic
int main(){ FAST

	ans = 1e5;
	cin >> N >> ma >> mb;
	FOR(i,1,N+1){
		cin >> a[i] >> b[i] >> c[i];
		//abc[i] = {c[i],a[i], b[i]};
	}
	//sort(abc+1,abc+N+1);
	FOR(i,1,N+1){
		//a[i] = abc[i][1], b[i] = abc[i][2], c[i] = abc[i][0];
		prefa[i] = prefa[i-1] + a[i];
		prefb[i] = prefb[i-1] + b[i];
	}

	F0R(i,N+1) F0R(j,401) F0R(k,401) DP[i][j][k] = 1e5;
	//DP[i][j][k] = min cost [1,i] of achieving j : k ratio for a : b, 1e9 if not possible

	DP[0][0][0] = 0;
	FOR(i,1,N+1){
		F0R(j,prefa[i-1]+1) F0R(k,prefb[i-1]+1) DP[i][j][k] = min(DP[i][j][k],DP[i-1][j][k]);
		F0R(j,prefa[i-1]+1){
			F0R(k,prefb[i-1]+1){
				int _j = j + a[i], _k = k + b[i];
				DP[i][_j][_k] = min(DP[i][_j][_k], DP[i-1][j][k] + c[i]);
			}
		}
	}
	//FOR(i,1,N+1) F0R(j,401) F0R(k,401) if (DP[i][j][k] != 1e5) bug(i _ j _ k _ DP[i][j][k]);
	FOR(j,1,prefa[N]+1) FOR(k,1,prefb[N]+1) if (j * mb == k * ma && DP[N][j][k] != 1e5) ans = min(ans, DP[N][j][k]); 	
	cout << (ans == 1e5 ? -1 : ans) << newl;


    return 0;
}
