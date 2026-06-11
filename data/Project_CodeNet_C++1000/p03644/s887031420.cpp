#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> V = { 1,2,4,8,16,32,64 };

int main() {
	int N;
	cin >> N;
	
	if (N >= 64) {
		cout << 64 << endl;
		return 0;
	}


	for (int i = 0; i < 7; i++) {
		if (V[i] <= N && V[i + 1] > N) {
			cout << V[i] << endl;
			return 0;
		}
	}
}