#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x;
	cin >> x;
	int sum = 0;
	for(int i=1;;i++) {
		sum += i;
		if(sum >= x) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
