#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int a[3];
	for(int i = 0; i < 3; i++)cin >> a[i];

	if(a[0] % 2 || a[1] % 2 || a[2] % 2) {
		cout << 0 << endl;
		return 0;
	}

	if(a[0] == a[1] && a[1] == a[2]) {
		cout << -1 << endl;
		return 0;	
	}
	int cnt = 0;
	while(a[0] % 2 == 0 && a[1] % 2 == 0 &&  a[2] % 2 == 0) {
		int nxt[3] = {};
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(i == j)continue;
				nxt[j] += a[i] / 2;
			}
		}
		for(int i = 0; i < 3; i++)a[i] = nxt[i];
		cnt++;
	}
	cout << cnt << endl;

}