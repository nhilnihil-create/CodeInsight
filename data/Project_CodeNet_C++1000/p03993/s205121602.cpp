#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)
typedef long long ll;

int main(){
	int N;
	cin >> N;

	vector<int> a(N);
	rep(i, N) cin >> a.at(i);
	int cnt = 0;
	rep(i, N){
		if (a.at(a.at(i) - 1) == i + 1) cnt++;
	}
	cout << cnt / 2 << endl;
}