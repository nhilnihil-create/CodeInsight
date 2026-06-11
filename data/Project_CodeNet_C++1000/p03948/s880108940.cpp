#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
static const int MAX_N = 100000;

int N, T;
int A[MAX_N];
map<int, int> mpa;

int main(){
	cin >> N >> T;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		mpa[A[i]]++;
	}
	int max_benefit = 0;
	int min_a = A[0];
	for(int i = 1; i < N; i++){
		min_a = min(min_a, A[i - 1]);
		max_benefit = max(max_benefit, A[i] - min_a);
	}
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(mpa[A[i] + max_benefit] > 0) ans++;
		mpa[A[i]]--;
	}
	cout << ans << endl;
	return 0;
}