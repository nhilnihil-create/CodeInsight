#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> s(N);
	int sum=0;
	for (int i = 0; i < N; i++) {
		cin >> s[i];
		sum += s[i];
	}
	if (sum % 10 != 0)cout << sum;
	else {
		int min_num = 101;
		for (int i = 0; i < N; i++) {
			if (min_num > s[i] && s[i] % 10 != 0)min_num = s[i];
		}
		if (min_num == 101)cout << 0;
		else cout << sum - min_num;
	}
}