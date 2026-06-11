#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n){
		int tmp;
		cin >> tmp;
		a[i] = --tmp;
	}
	
	int ans = 0;
	for(int i = 0; i < n; ++i){
		if(i == a[a[i]]){
			ans++;
		}
	}
	
	cout << ans / 2 << endl;
	return 0;
}

