#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

string A[60], B[60];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];
	for (int i = 0; i <= N - M; i++) {
		for (int j = 0; j <= N - M; j++) {
			//cout << i << " " << j << endl;
			bool ok = true;
			for (int k = 0; k < M; k++) {
				if (A[i + k].substr(j, M) != B[k].substr(0, M)) {
					ok = false;
					break;
				}
			}
			if (ok) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}
