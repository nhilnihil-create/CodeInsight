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

int main(){	
	long long N;
	scanf("%lld",&N);
	vector<long long> a(N-1+1);
	for(int i = 0 ; i <= N-1 ; i++){
		scanf("%lld",&a[i]);
	}
	ll minv = 10000000, maxv = -1; 
	rep(i,N) {
		minv = min(minv, a[i]);
		maxv = max(maxv, a[i]);
	}
	if (maxv-minv > 1) {
		cout << "No" << endl;
		return 0;
	}
	if (maxv-minv == 0) {
		if (minv <= N/2 || minv == N-1) {
			cout << "Yes" << endl;
			return 0;
		} else {
			cout << "No" << endl;
			return 0;
		}
	}
	ll c = 0;
	rep(i,N) {
		if (a[i] == minv) c++;
	}
	if (c+1 <= maxv && maxv <= c+(N-c)/2) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}

