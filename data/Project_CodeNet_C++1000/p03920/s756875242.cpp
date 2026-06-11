#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<set>
#include<fstream>
#include<map>
#include<vector>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> P;

int bs(int n) {
	int lb = 0, ub = 114514;
	while (ub - lb > 1) {
		int mi = (lb + ub) / 2;
		if (mi*(mi+1)/2<n)lb = mi;
		else ub = mi;
	}
	return ub;
}

signed main() {
	int n; cin >> n;
	while (n) {
		int a = bs(n);
		cout << a << endl;
		n -= a;
	}
}
