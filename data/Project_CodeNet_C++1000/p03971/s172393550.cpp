#include<iostream>
#include<vector>
using namespace std;
int main() {
	int N,A,B;
	cin >> N >> A >> B;
	vector<char> V(N);
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}
	int count = 0;
	int countb = 1;
	for (int i = 0; i < N; i++) {
		if (V[i] == 'a') {
			if (count < A + B) {
				count++;
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		else if (V[i] == 'b') {
			if (count < A + B && countb <= B) {
				count++;
				countb++;
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}