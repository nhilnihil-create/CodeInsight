#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<map>
#define ran(x) (x).begin(),(x).end()
using namespace std;
int main() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int k = 0;
	map<int, int> b;
	for(int i = 0; i < n; ++i) {
		++b[k];
		k = a[k]-1;
		if(b[k] > 1)
			return cout << -1 << endl, 0;
		if(k == 1)
			return cout << i+1 << endl, 0;
	}//*/
}