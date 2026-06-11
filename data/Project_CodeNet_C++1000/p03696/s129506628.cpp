#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	int N;
	char c;
	int count = 0;
	int min_count = 0;
	// int max_count = 0;
	scanf("%d", &N);
	scanf("%c", &c);
	string S;

	cin >> S;
	for (int i = 0; i < N; i++) {
		if (S[i] == '(') {
			count++;
			// max_count = max(max_count, count);
		} else if (S[i] == ')') {
			count--;
			min_count = min(min_count, count);
		} else {
			break;
		}
		// printf("count = %d\n", count);
	}

	for (int i = 0; i < -min_count; i++) {
		printf("(");
	}
	cout << S;
	for (int i = 0; i < count - min_count; i++) {
		printf(")");
	}

	return 0;
}