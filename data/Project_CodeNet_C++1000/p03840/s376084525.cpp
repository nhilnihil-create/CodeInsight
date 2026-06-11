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

void solve(long long a_I, long long a_O, long long a_T, long long a_J, long long a_L, long long a_S, long long a_Z){
	ll res = a_I/2*2+a_O+a_J/2*2+a_L/2*2;
	if (a_I > 0 && a_J > 0 && a_L > 0) res = max(res, (a_I-1)/2*2+a_O+(a_J-1)/2*2+(a_L-1)/2*2+3);
	cout << res << endl;
}

int main(){	
	long long a_Z;
	long long a_S;
	long long a_L;
	long long a_J;
	long long a_T;
	long long a_O;
	long long a_I;
	scanf("%lld",&a_I);
	scanf("%lld",&a_O);
	scanf("%lld",&a_T);
	scanf("%lld",&a_J);
	scanf("%lld",&a_L);
	scanf("%lld",&a_S);
	scanf("%lld",&a_Z);
	solve(a_I, a_O, a_T, a_J, a_L, a_S, a_Z);
	return 0;
}

