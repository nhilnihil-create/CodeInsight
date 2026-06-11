#include <iostream>
#define inf 1000000000

using namespace std;

int N, T;
int A[100005];
int dif[100005];

int main(void)
{
	cin >> N >> T;
	for(int i = 0; i < N; i++) cin >> A[i];
	
	int m = inf, M = -inf;
	for(int i = 0; i < N; i++){
		dif[i] = A[i] - m;
		M = max(M, dif[i]);
		m = min(m, A[i]);
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++){
		if(dif[i] == M) ans++;
	}
	cout << ans << endl;
	return 0;
}