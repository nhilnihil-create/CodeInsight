#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<vector>
using namespace std;
int main() {

	long long int x, y;
	cin >> x >> y;
	if (abs(x - y) <= 1) {
		cout << "Brown" << endl;
	}
	else {

		cout << "Alice" << endl;

	}
	return 0;

	/*int n;
	cin >> n;
	long long int a[100000];
	int i;
	long long int sum = 0, counter = 0;
	for(i = 0;i<n;i++){
		cin >> a[i];

		if (sum < 0) {
			if (sum + a[i] <= 0) {
				counter = counter + abs(-sum + 1 - a[i]);
				a[i] = -sum + 1;
			}
			
		}
		else if (sum > 0){
			if (sum + a[i] >= 0) {
				counter = counter + abs(-sum - 1 - a[i]);
				a[i] = -sum - 1;
			}
		}
		sum = sum + a[i];
		//cout << counter << ' ';
	}
	cout << counter << endl;
	return 0;
	*/
}