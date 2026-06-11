# include <bits/stdc++.h>

using namespace std;

long long N;

vector<int> ans;

int m;
deque<int> q;

void get(long long N) {
	if(N == 0) return;
	if(N & 1) {
		get(N >> 1);
		q.push_back(q.size() + 1);
	} else {
		get(N - 1);
		q.push_front(q.size() + 1);
	}
}

int main() {
	cin >> N;
	get(N);
	int n = q.size();
	ans.resize(n * 2);
	for(int i = 0; i < n; ++i) {
		ans[i] = *q.begin();
		q.pop_front();
		ans[i + n] = i + 1;
	}
	printf("%d\n", n * 2);
	for(int i = 0; i < n * 2; ++i) {
		printf("%d%c", ans[i], " \n"[i==n*2]);
	}
	return 0;
}
