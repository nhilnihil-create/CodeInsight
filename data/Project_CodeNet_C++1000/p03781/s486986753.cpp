#include <bits/stdc++.h>
using namespace std;

int main() {
	int x;
	cin >> x;
	for(int i = 1;true;i++){
		x -= i;
		if(x < 1){
			cout << i << endl;
			return 0;
		}
	}
}