#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 998244353;
const long double EPS = 0.00000001;


long long int N, M, K, L, R, H, W;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	
	int num[200000];
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	int box = 0;

	for (int i = 0; i < N; i++) {
		if (num[i] > box + 1) {
			M += (num[i]-1) / (box + 1);
			box = max(box, 1);
		}
		else {
			box = max(box,num[i]);
		}
		//cout << " " << M << endl;
	}
	cout << M << endl;
	return 0;
}
