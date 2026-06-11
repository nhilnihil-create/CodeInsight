#include<iostream> 

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k, x,y=0;
	cin >> n >> k;
	rep(i, n) {
		cin >> x;
		if (x > k) {
			y += (x - k) ;
		}
		else if (k - x < x) {
			y += (k - x) ;
		}
		else {
			y += x ;
		}
	}
	cout << y*2 << endl;
	return 0;
}