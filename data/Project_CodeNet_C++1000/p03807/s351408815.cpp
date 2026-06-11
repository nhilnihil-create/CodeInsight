#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	int counts = 0;
	rep(i,n){
		if(a[i]%2 == 1) counts++;
	}
	if(counts%2 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}