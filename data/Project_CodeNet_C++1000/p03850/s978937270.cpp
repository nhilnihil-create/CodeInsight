#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);
 
ll sum[100001], asum[100001];
vi neg;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	cin >> sum[1]; asum[1] = sum[1];
	
	FOR(i,2,N+1) {
		char op; int A;
		cin >> op >> A;
		if (op == '-') neg.pb(i), A = -A;
		sum[i] = sum[i-1]+A;
		asum[i] = asum[i-1]+abs(A);
	}
	ll ans = sum[N];
	neg.pb(N+1);
	F0R(i,neg.size()-1) {
		ll cur = sum[neg[i]-1];
		cur -= (asum[neg[i+1]-1]-asum[neg[i]-1]);
		cur += (asum[N]-asum[neg[i+1]-1]);
		ans = max(ans,cur);
	}
	cout << ans;
}