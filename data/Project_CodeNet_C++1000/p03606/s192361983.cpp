#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	int start, end;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		num = end - start + 1;
		count += num;
	}
	cout << count << endl;
}