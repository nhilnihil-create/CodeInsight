#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <set>
#include <cstdlib>
#include <queue>

using namespace std;

typedef long long llint;
typedef long double ld;
#define inf 1e18
#define mod 1000000007
priority_queue<llint,vector<llint>,greater<llint>> que;
priority_queue<llint> q;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

llint n,a,b;
llint x[100005];

llint calc(int i){
	llint ret;
	ret=x[i]-x[i-1];
	ret*=a;
	return min(ret,b);
}

void solve(){
	cin >>n >> a >> b;
	for(int i=0;i<n;i++)cin >> x[i];
	llint ans=0;
	//ans+=min((x[0]-1)*a,b);
	for(int i=1;i<n;i++){
		ans+=calc(i);
	}
	cout << ans << endl;
}

int main() {
  solve();
  return 0;
}
