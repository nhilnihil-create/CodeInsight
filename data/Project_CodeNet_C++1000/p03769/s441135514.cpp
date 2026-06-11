#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, u, d;
vector<ll> x, ans;

int main()
{
	scanf("%lld",&n);
	while(n > 1) {
		if(n%2) {x.push_back(1); n /= 2;}
		else {x.push_back(0); n--;}
	}
	reverse(x.begin(), x.end());
	ans.push_back(0);
	for(auto &T : x) {
		if(T) ans.push_back(++u);
		else ans.push_back(--d);
	}
	printf("%d\n",2*ans.size());
	for(ll i=0;i<ans.size();i++) printf("%lld ", i+1);
	for(ll i=0;i<ans.size();i++) printf("%lld ", ans[i]-d+1);
}
