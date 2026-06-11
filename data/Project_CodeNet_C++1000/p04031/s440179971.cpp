#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int cost(vector<int> a, int x){
	int ret = 0;
	for(auto y : a){
		ret += (x - y)*(x - y);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	vector<int> a(n);
	int sum = 0;
	for(auto &x : a){
		cin>>x;
		sum += x;
	}
	int ans = min(cost(a, sum/n), cost(a, sum/n + 1));
	cout<<ans<<endl;

	return 0;
}