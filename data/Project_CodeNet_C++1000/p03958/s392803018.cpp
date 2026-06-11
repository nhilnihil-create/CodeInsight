#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
	int k,t;
	cin >> k >> t;
	vector<int> a(k);
	for(int i = 0; i < t; i++) cin >> a[i];
	sort(a.begin(),a.end(),greater<int>());
	if(k >= 2*a[0]) cout <<  0 << endl;
	else cout << 2*a[0]-k-1 << endl;
	return 0;
}