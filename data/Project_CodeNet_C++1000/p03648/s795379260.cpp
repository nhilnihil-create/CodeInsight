#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

void print(vector<int> &v, int N) {
	cout << N << endl;
	for(int i = 0; i < N; ++i) {
		cout << v[i] << (i == N - 1 ? "\n": " ");
	}
}
void func(vector<int> &v) {
	int N = v.size();
	int idx = 0;
	for(int i = 1; i < N; ++i) {
		if(v[idx] < v[i]) {
			idx = i;
		}
	}
	for(int i = 0; i < N; ++i) {
		if(i == idx) {
			v[i] -= N;
		} else {
			v[i]++;
		}
	}
}

bool finished(const vector<int> &v) {
	int N = v.size();
	for(int i = 0; i < N; ++i) {
		if(v[i] >= N) {
			return false;
		}
	}
	return true;
}

bool check(vector<int> v, int m) {
	int N = v.size();
	for(int i = 0; i < m; ++i) {
		if(finished(v)) return false;
		func(v);
	}
	return finished(v);
}

signed main(){
	int K;
	cin >> K;
	const int N = 50;
	int m = (N - K % N) % N, l = (K + N - 1) / N;
	vector<int> v(N, l + 49);
	for(int i = 0; i < m; ++i) {
		func(v);
	}
	print(v, N);
	return 0;
}
