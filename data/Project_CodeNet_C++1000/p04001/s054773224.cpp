#include<iostream>
using namespace std;
int main() {

	long long int sum = 0;
	string s;
	cin >> s;
	int i;
	int bin[10] = { 1,2,4,8,16,32,64,128,256,512 };
	int j;
	long long int k;
	for (i = 0; i < bin[s.size() - 1]; i++) {
		k = (s[0] - '0');
		for (j = 0; j < s.size() - 1; j++) {
			if ((i ^ bin[j]) == (i + bin[j])) {
				sum = sum + k;
				//cout << k << endl;
				k = (s[j + 1] - '0');
			}
			else {
				k = k * 10;
				k = k + (s[j + 1] - '0');
			}
		}
		sum = sum + k;
		//cout << k << endl;
	}
	cout << sum << endl;
	return 0;
}