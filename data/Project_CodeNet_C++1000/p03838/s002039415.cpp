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
#define INF 1000000000000
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

void solve(long long x, long long y){
	ll res = INF;
	if (y-x >= 0) res = min(res, y-x);
	if (-y-x >= 0) res = min(res, -y-x+1);
	if (y+x >= 0) res = min(res, y+x+1);
	if (-y+x >= 0) res = min(res, -y+x+2);
	cout << res << endl;
}

int main(){	
	long long x;
	long long y;
	scanf("%lld",&x);
	scanf("%lld",&y);
	solve(x, y);
	return 0;
}

