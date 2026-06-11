#include <bits/stdc++.h>
using namespace std;

int main () {
	int N;
	int first, last;
	int count = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> first >> last;
		count += (last - first) + 1;
	}
	cout << count << endl;
}
