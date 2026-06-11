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

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (i * (M - j) + j * (N - i) == K) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}