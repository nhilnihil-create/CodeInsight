#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	string s; cin >> s;
	for (int p = 0; p < 4; p++) {
		int flag =  0;
		vector<int> ani(N, 2);
		int temp = p;
		ani[N - 1] = temp % 2;
		temp /= 2;
		ani[1] = temp % 2;
		if (ani[N - 1] == ani[1])
			ani[0] = (s[0] == 'o' ? 0 : 1);
		else
			ani[0] = (s[0] == 'x' ? 0 : 1);
		for (int i = 1; i < N - 2; i++) {
			if (ani[i] == 0 )
				ani[i + 1] = (s[i] == 'o' ? ani[i - 1] : (ani[i - 1] + 1) % 2);
			else if (ani[i] == 1)
				ani[i + 1] = (s[i] == 'o' ? (ani[i - 1] + 1) % 2 : ani[i - 1]);
		}

		if (ani[N - 2] == 0) {
			if (s[N - 2] == 'o' && ani[N - 3] == ani[N - 1])
				flag++;
			else if (s[N - 2] == 'x' && ani[N - 3] != ani[N - 1])
				flag++;
		}
		else if (ani[N - 2] == 1) {
			if (s[N - 2] == 'o' && ani[N - 3] != ani[N-1])
				flag++;
			else if (s[N - 2] == 'x' && ani[N - 3] == ani[N-1])
				flag++;
		}
		if (ani[N - 1] == 0) {
			if (s[N - 1] == 'o' && ani[N - 2] == ani[0])
				flag++;
			else if (s[N - 1] == 'x' && ani[N - 2] != ani[0])
				flag++;
		}
		else if (ani[N - 1] == 1) {
			if (s[N - 1] == 'o' && ani[N - 2] != ani[0])
				flag++;
			else if (s[N - 1] == 'x' && ani[N - 2] == ani[0])
				flag++;
		}
		if (flag==2) {
			for (int i = 0; i < N; i++)
				cout << (ani[i] == 0 ? 'S' : 'W');
			cout << endl;
			break;
		}
		if (flag != 2 && p == 3) cout << -1 << endl;
	}
	
}
