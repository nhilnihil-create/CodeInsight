#include <iostream>
using namespace std;
int main(){
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	int max=a[0];
	int total = a[0] + a[1] + a[2];
	for (int i = 0;i < 3;i++) {
		if (max < a[i]) max = a[i];
	}
	if (max == total - max) cout << "Yes";
	else cout << "No";
}