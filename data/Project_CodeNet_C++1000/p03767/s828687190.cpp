#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(3*n);
	rep(i,3*n) cin >> a[i];
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	ll sum = 0;
	for(int i = 1; i <=2*n; i+=2){
		sum += a[i];
	}
	cout << sum << endl;
}