#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<pair<int,int>> input(N);

	for(int i = 0; i < N; ++i) {
		cin >> input[i].first >> input[i].second;
	}

	vector<pair<int,int>> input2(M);
	for(int loop = 0; loop < M; ++loop) {
		cin >> input2[loop].first >> input2[loop].second;
	}

	for(int loop = 0; loop < N; ++loop) {
		int mi = 1e9;
		int result = 0;
		for(int loop2 = 0; loop2 < M; ++loop2) {
			int t = abs(input2[loop2].first - input[loop].first) + abs(input2[loop2].second - input[loop].second);
			if (mi > t) {
				mi = t;
				result = loop2 + 1;
			}
		}
		cout << result << endl;
	}

	return 0;
}
