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
	string S;
	int K;
	cin >> S >> K;
	int L = S.size();
	for (int i = 0; i < L; i++) {
		int n = S[i] - 'a';
		if (K >= 26 - n) {
			K -= (26 - n) % 26;
			S[i] = 'a';
		}
	}
	S[L - 1] = (char)(((S[L - 1] - 'a' + K) % 26) + 'a');
	cout << S << endl;
}