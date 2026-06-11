#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(void) {
	string w;
	cin >> w;
	int temp[100], ans = 0;


		for (int i = 0; i < w.length(); i++) {
			temp[i] = 0;
			for (int j = 0; j < w.length(); j++) {

				if (w[i] == w[j])temp[i]++;
			}
		}
		for (int i = 0; i < w.length(); i++) {
			ans += temp[i];
		}
		for (int i = 0; i < w.length(); i++) {
			
			if (temp[i] % 2 != 0) {
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
		


	return 0;
}