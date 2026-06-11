#include<cstdio>
#include<iostream>
using namespace std;

bool judge(string s1, string s2) {
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] < s2[i]) {
			return true;
		} else if (s1[i] > s2[i]) {
			return false;
		}
	}
	return false;
}
int main(void) {
	int N, L;
	scanf("%d %d", &N, &L);
	string S[100];
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			// cout << i << " " << j << "\n";
			// cout << S[j] << " " << S[j + 1] << "\n";
			if (!judge(S[j], S[j + 1])) swap(S[j], S[j + 1]);
		}
	}
	for (int i = 0; i < N; i++) {
		cout << S[i];
	}
	cout << "\n";
	return 0;

}
