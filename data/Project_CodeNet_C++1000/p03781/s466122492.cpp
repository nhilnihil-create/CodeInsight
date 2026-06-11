#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> v;
int main() {
	cin >> N;
	for (int i = 0; i <= 100000000; ++i) {
		if (i*(i + 1) / 2 >= N) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}