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

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> K;
	if (K % 2) {
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if ((i + j) % 2) {
					cout << "R";
				}
				else {
					cout << "G";
				}
			}
			cout << endl;
		}
		return 0;
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if ((i + j) % (K * 2) < K) {
				if ((i - j + K * 1000) % (K * 2) < K) {
					cout << "R";
				}
				else{
					cout << "G";
				}
			}
			else {
				if ((i - j + K * 1000) % (K * 2) < K) {
					cout << "Y";
				}
				else {
					cout << "B";
				}
			}
		}
		cout << endl;
	}
	return 0;
}