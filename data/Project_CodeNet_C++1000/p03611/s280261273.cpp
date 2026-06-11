#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	vector<int> num(100010,0);
	for (int i = 0; i < N; i++) {
		num[a[i]]++;
	}
	vector<int> ans(100010, 0);
	for (int i = 0; i < num.size(); i++) {
		if (i == 0)ans[i] = num[i] + num[i + 1];
		else if (i == num.size() - 1)ans[i] = num[i - 1] + num[i];
		else ans[i] = num[i - 1] + num[i] + num[i + 1];
	}
	int ANS=0;
	for (int i = 0; i < ans.size(); i++) {
		if (ANS < ans[i])ANS = ans[i];
	}
	cout << ANS;
}