#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int N, M;
	cin >> N;

	vector<int> T(N);
	int sum = 0;
	rep(i, N){
		cin >> T.at(i);
		sum += T.at(i);
	}
	cin >> M;

	vector<pair<int, int>> drink(M);
	rep(i, M) cin >> drink.at(i).first >> drink.at(i).second;
	rep(i, M){
		int ans = sum;
		ans -= T.at(drink.at(i).first - 1) - drink.at(i).second;
		cout << ans << endl;
	}
}