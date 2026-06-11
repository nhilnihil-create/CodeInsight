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

int main(){
	long long int N;
	cin >> N;
	vector<long long int> A(N), diff(N);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	if(N == 1){
		cout << "YES" << endl;
		return 0;
	}
	diff[0] = A[0] - A[N - 1];
	long long int rem = (diff[0] % N + N) % N;
	long long int cnt = diff[0];
	for(int i = 1; i < N; i++){
		diff[i] = A[i] - A[i - 1];
		if(rem != (diff[i] % N + N) % N){
			cout << "NO" << endl;
			return 0;
		}
		cnt = max(cnt, diff[i]);
	}
	for(int i = 0; i < N; i++){
		if(cnt != diff[i]){
			A[N - 1] -= (cnt - diff[i]) / N * (N - i);
		}
	}
	if(A[N - 1] >= 0 && A[N - 1] % (N * (N + 1) / 2) == 0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}