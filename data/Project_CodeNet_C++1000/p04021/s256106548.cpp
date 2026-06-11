#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void compress(vector<int> &a){
	vector<int> b = a;
	sort(b.begin(), b.end());
	for(auto &x : a){
		x = lower_bound(b.begin(), b.end(), x) - b.begin();
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &x: a){
		cin>>x;
	}
	compress(a);
	int ans = 0;
	for(int i = 0; i < n; i++){
		if((i^a[i])&1)ans++;
	}
	cout<<ans/2<<endl;

	return 0;
}