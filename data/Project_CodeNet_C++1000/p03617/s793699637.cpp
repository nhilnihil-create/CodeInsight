#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define ppb pop_back
#define vll vector<ll>
#define vi vector<int>
#define endl "\n"

const ll INF = 1000000007;

/*
const int max_size = 100001;
int parent[max_size];
int Size[max_size];

int root(int x){
	while(x!=parent[x]){
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void sunion(int x,int y){
	int rx = root(x);
	int ry = root(y);
	if(rx != ry){
		if(Size[rx] > Size[ry]){
			parent[ry] = parent[rx];
			Size[rx] += Size[ry];
		}
		else{
			parent[rx] = parent[ry];
			Size[ry] += Size[rx];
		}
	}
}
*/

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin >> t;
	while(t--){
		ll q,h,s,d;
		cin >> q >> h >> s >> d;
		ll n;
		cin >> n;
		ll a1;
		a1 = n/2;
		ll cst = min(min(8*q,4*h),min(2*s,d));
		ll ans = a1*cst;
		a1 = n%2;
		cst = min(min(4*q,2*h),s);
		ans += (a1*cst);
		cout << ans << endl;
	}
	return 0;
}
