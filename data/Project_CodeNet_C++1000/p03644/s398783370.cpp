#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int N = 0;
	cin >> N;
	int check = 0;
	while (1) {
		if (pow(2, check) > N) {
			check--;
			break;
		}
		check++;
	}
	cout << pow(2, check) << endl;
	return 0;
}