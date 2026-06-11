#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using v2 = vector<vector<int>>;

int main(){
	int n, k;
	cin >> n >> k;
	ll c = k;
	rep(i, n-1){
		c *= k-1;
	}
	cout << c << endl;
}
