#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;
// vector<vector<int>> data(3, vector<int>(4));

void solve(long long W, long long H, vector<long long> p, vector<long long> q){
	SORT(p);
	SORT(q);
	ll pivp = 0, pivq = 0, res = 0;
	while(pivp != W || pivq != H) {
		if (pivq == H || (pivp != W && p[pivp] < q[pivq])) {
			res += p[pivp]*(H-pivq+1);
			// cout << "p " << p[pivp] << " " << (H-pivq+1) << " " << p[pivp]*(H-pivq+1) << endl;
			pivp++;
		} else {
			res += q[pivq]*(W-pivp+1);
			// cout << "q " << q[pivq] << " " << (W-pivp+1) << " " << q[pivq]*(W-pivp+1) << endl;
			pivq++;
		}
	}
	cout << res << endl;
}

int main(){	
	long long W;
	long long H;
	scanf("%lld",&W);
	vector<long long> p((W-1)-0+1);
	scanf("%lld",&H);
	vector<long long> q((H-1)-0+1);
	for(int i = 0 ; i <= (W-1)-0 ; i++){
		scanf("%lld",&p[i]);
	}
	for(int i = 0 ; i <= (H-1)-0 ; i++){
		scanf("%lld",&q[i]);
	}
	solve(W, H, p, q);
	return 0;
}

