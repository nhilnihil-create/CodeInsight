#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
	int A, B, N;
	int fore = 0;
	int dom = 0;
	string s;
	cin >> N >> A >> B;
	cin >> s;
	for (int i = 0; i < N; i++) {
		if (s[i] == 'a') {
			if (dom + fore < A + B) {
				cout << "Yes" << endl;
				dom++;
			}
			else cout << "No" << endl;
			

		}
		else if (s[i] == 'b') {
			if (dom + fore < A + B && fore < B) { cout << "Yes" << endl; fore++;
			}
			else cout << "No" << endl;
			
		}

		else cout << "No" << endl;
	}
	return 0;
}
