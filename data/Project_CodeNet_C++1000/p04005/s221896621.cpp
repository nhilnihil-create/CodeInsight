#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
ll box[2];
int main() {
	for (int i = 0; i < 3; i++) {
		cin >> box[i];
	}
	if (box[0] % 2 == 0 || box[1] % 2 == 0 || box[2] % 2 == 0) {
		cout << "0" << endl;
	}
	else {
		sort(box, box + 3);
		
		cout << box[0] * box[1] << endl;

	}
	return 0;
}