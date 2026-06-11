#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string A;
	cin >> A;
	int N = A.size();
	long long ans = (long long) N * (N + 1) / 2 + 1;
	vector<int> cnt(26, 0);
	for (int i = 0; i < N; i++){
		cnt[A[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++){
		ans -= (long long) cnt[i] * (cnt[i] + 1) / 2;
	}
	cout << ans << endl;
}