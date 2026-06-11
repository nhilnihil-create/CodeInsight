#include<bits/stdc++.h>
using namespace std;

#define deb(x) cerr<<"["#x<<" : "<<x<<" ]\n";

int main()
{
	int n, total = 0;
	cin >> n;
	vector<int> in(n);
	for(int &i: in) {
		cin >> i;
		total += i;
	}
	int m;
	cin >> m;
	while(m--) {
		int p, x;
		cin >> p >> x;
		cout << total - in[p-1] + x << '\n';
	}
}
