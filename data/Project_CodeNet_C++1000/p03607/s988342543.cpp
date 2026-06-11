#include<bits/stdc++.h>
using namespace std;

map<int, int> r;

int main() {
	int n; cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int a; cin >> a;
		if(r[a] == 0) {
			res++;
			r[a] = 1;
		}
		else {
			res--;
			r[a] = 0;
		}
	}
	cout << res << endl;
	return 0;
}
