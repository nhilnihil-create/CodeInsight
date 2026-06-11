#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
int main(){
	int n,ans = 0;
	cin >> n;
	n*=2;
	vector<int> v;
	while (n--){
		int a;
		cin >> a;
		v.pb(a);
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < v.size(); i+=2)
		ans += v[i];
	cout << ans;
	return 0;
}