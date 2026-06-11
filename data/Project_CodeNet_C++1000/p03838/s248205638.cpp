#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll x,y;cin>>x>>y;
	ll ans;
	if (x <= y){
		ans = abs(y - x);
		if (x < 0 && abs(x) <= y){
			ans = min(ans,1 + y - abs(x));
		}
		else if (x < 0 && abs(x) > y){
			ans = min(ans,1 + abs(abs(y) - abs(x)));

		}
	}
	else{
			ans = 1 + abs(abs(y) -  abs(x));
			if(x * y > 0){
			ans = 2 + abs(abs(y) - abs(x));
		}
	}
	cout << ans << endl;
	return 0;
}