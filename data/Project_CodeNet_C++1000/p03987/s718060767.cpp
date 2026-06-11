#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i,n) {
		cin >> p[i];
		p[i]--;
	}
	
	vector<int> idx(n);
	rep(i,n) idx[p[i]] = i;
	
	set<int> sidx;
	ll res = 0;
	rep(i,n){
		sidx.insert(idx[i]);
		auto itr = sidx.find(idx[i]);
		
		
		ll l1 = 0;
		ll r1 = 0;
		
		// L
		auto litr = itr;
		if(litr != sidx.begin()){
          litr--;
			l1 = idx[i] - *litr;
		}
		else{
			l1 = idx[i]+1;
		}
		
		// R
		auto ritr = itr;
		if(++ritr != sidx.end()){
			r1 = *ritr - idx[i];
		}
		else{
			r1 = n - idx[i];
		}
		
		// cout << l1 << r1 << endl;
		res += ( l1 * r1  ) * (i+1);
	}
	
	cout << res << endl;
	return 0;
}