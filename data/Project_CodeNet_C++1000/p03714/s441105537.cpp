#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cmath>
#include <limits>
#include <utility>
#include <map>
#include <iomanip>
#include <queue>


#define rep(p,q) for(int i = p;i < q;i++)
#define ll long long

using namespace std;



//62D
int main(void) {
	priority_queue<ll,vector<ll>,greater<ll>> f;
	priority_queue<ll,vector<ll>> b;
	ll n;
	vector<ll> as;
	vector<ll> f_ans, b_ans;
	std::cin >> n;
	ll fSum = 0, bSum = 0;
	rep(0, 3*n) {
		ll a;
		std::cin >> a;
		if (i < n) {
			f.push(a);
			
			fSum += a;
		}
		else if (i < 2 * n) {
			as.push_back(a);
		}
		else{
			b.push(a);
			bSum += a;
		}
	}

	f_ans.push_back(fSum);
	
	rep(0, n) {		
		f.push(as[i]);
		ll del = f.top();
		f.pop();
		fSum += as[i];
		fSum -= del;
		f_ans.push_back(fSum);
	}

	b_ans.push_back(bSum);
	for (ll i = n-1; i >= 0; i--) {
		b.push(as[i]);
		ll del = b.top();
		b.pop();
		bSum += as[i];
		bSum -= del;
		b_ans.push_back(bSum);
	}
	ll ans = -1 * pow(10, 14);
	reverse(b_ans.begin(), b_ans.end());
	rep(0, n+1) {
		ans = max(ans, f_ans[i] - b_ans[i]);
	}
	cout << ans << endl;
}