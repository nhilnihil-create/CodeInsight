#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;

int x,y,z,n,m,ans1[200005],ans2[200005],order[200005];

int main() {
	cin >> x;
	for (int i = 1; i <= x; i++) {
		cin >> y;
		order[y] = i;
	}
	ans1[1] = ans2[1] = 500000000;
	for (int i = 2; i <= x; i++) {
		int tmp = order[i] - order[i-1];
		if (tmp < 0) {
			ans1[i] = ans1[i-1]+1;
			ans2[i] = ans2[i-1]-1+tmp;
		} else {
			ans1[i] = ans1[i-1]+1+tmp;
			ans2[i] = ans2[i-1]-1;			
		}
	}
	for (int i = 1; i <= x; i++) {
		cout << ans1[i] << " ";
	}
	cout << "\n";
	for (int i = 1; i <= x; i++) {
		cout << ans2[i] << " ";
	}
}