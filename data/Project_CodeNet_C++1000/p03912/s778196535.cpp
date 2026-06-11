#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, m; cin >> n >> m;
	vector<int>C(n);
	for (int i = 0; i < n; i++){
		cin >> C[i];
	}
	sort(C.begin(), C.end());

	vector<vector<int>>X(m);
	vector<int>Y(m);

	int pre = C[0];
	int cnt = 1;
	for (int i = 1; i < C.size(); i++){
		if (C[i] == pre) cnt++;
		else{
			X[pre%m].push_back(cnt);
			Y[pre%m] += cnt;
			pre = C[i];
			cnt = 1;
		}
	}
	X[pre%m].push_back(cnt);
	Y[pre%m] += cnt;

	int p = 0;
	for (int i = 1; i <= m/2 - !(m%2); i++){
		int tmp_p;
		tmp_p = min(Y[i], Y[m - i]);
		//cout << tmp_p << endl;
		Y[i] -= tmp_p;
		Y[m - i] -= tmp_p;
		p += tmp_p;
	}
	p += Y[0] / 2;
	if (!(m % 2))p += Y[m / 2] / 2;

	//cout << p << endl;

	for (int i = 1; i < m; i++){
		Y[i] /= 2;
		if (!(m % 2))if (i == m / 2)continue;
		for (int j = 0; j < X[i].size(); j++){
			if (X[i][j] >= 2){
				p += min(Y[i], X[i][j] / 2);
				Y[i] -= X[i][j] / 2;
				if (Y[i] <= 0)break;
			}
		}
	}

	cout << p << endl;

	return 0;
}