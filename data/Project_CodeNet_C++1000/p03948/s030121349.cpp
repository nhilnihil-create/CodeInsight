#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	llong N, T;
	vector<llong> A;

	cin >> N >> T;
	A.resize(N);
	for(int i = 0; i < N; i++)
		cin >> A[i];

	llong score = -inf, many = 0;
	llong mini = A[0];
	for(int i = 1; i < N; i++){
		if(score == A[i] - mini)
			many++;
		else if(score < A[i] - mini)
			score = A[i] - mini, many = 1;

		mini = min(mini, A[i]);
	}

	cout << many << endl;

	return 0;
}