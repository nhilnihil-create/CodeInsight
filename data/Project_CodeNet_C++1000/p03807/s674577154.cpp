#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	//奇数と偶数の数を数えたい(配列それぞれについて数えるから、n回)
	int ki = 0;
	int gu = 0;
	for (int i = 0; i < n; i++) {
		//a.at(i)が奇数か偶数かを決めたい
		if (a.at(i) % 2 == 0) gu++;
		else ki++;
	}
	if (ki%2==0||(ki==1&&gu==0)) cout << "YES" << endl;
	else cout << "NO" << endl;

}