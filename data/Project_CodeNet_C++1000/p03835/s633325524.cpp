#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <map>
using namespace std;


int main() {
	int K, S;
	cin >> K;
	cin >> S;
	int cont = 0;

	for (int i=0;i<=K;i++){

		for (int j = 0; j<=K; j++) {
			int z = S - i - j;
			if (z>= 0 && z <= K) {
				++cont;
			}
		
		}
	}
	cout << cont << endl;

	return 0;
}