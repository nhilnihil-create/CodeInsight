#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map> 
#include <unordered_set>
#include <functional>

using namespace std;

typedef pair<long long int, long long int> P;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int memo[310000];

int main(){
	int N;
	cin >> N;
	priority_queue<long long int> que;
	priority_queue<long long int, vector<long long int>, greater<long long int>> que2;
	vector<long long int> a(3 * N);
	for(int i = 0; i < 3 * N; i++){
		cin >> a[i];
	}
	long long int S = 0;
	for(int i = 0; i < N; i++){
		S += a[i];
		que2.push(a[i]);
	}
	memo[N - 1] = S;
	for(int i = N; i < 2 * N; i++){
		S += a[i];
		que2.push(a[i]);
		S -= que2.top();
		que2.pop();
		memo[i] = S;
	}
	S = 0;
	for(int i = 3 * N - 1; i >= 2 * N; i--){
		S += a[i];
		que.push(a[i]);
	}
	long long int ans = memo[2 * N - 1] - S;
	for(int i = 2 * N - 1; i >= N; i--){
		S += a[i];
		que.push(a[i]);
		S -= que.top();
		que.pop();
		ans = max(ans, memo[i - 1] - S);
	}
	cout << ans << endl;
	return 0;
}