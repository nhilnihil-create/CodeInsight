#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;

int main(){
	int n;
	cin >> n;
	ll w = 1e9 + 7;
	ll power = 1;
	int c = 1;
	rep(i, n){
		power *= c;
		c++;
		power %= w;
	}
	cout << power << endl;
}
