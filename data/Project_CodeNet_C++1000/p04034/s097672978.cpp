#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n, m; cin >> n >> m;
	vector<int> num(n, 1);
	vector<int> red(n);
	red[0] = true;

	for(int i = 0; i < m; i++) {
		int x, y; cin >> x >> y; x--, y--;
		num[x]--, num[y]++;
		if(!red[x]) {
			continue;
		}

		if(num[x] == 0) {
			red[x] = false;
			red[y] = true;
		} else {
			red[y] = true;
		}
	}
	cout << count(red.begin(), red.end(), 1) << endl;
}