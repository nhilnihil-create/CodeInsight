#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int list[] = {1, 2, 4, 8, 16, 32, 64};
	for(int i = 6; i >= 0; i--){
		if(list[i] <= n){
			cout << list[i] << endl;
			return 0;
		}
	}
}
