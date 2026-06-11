#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <cmath>

#define	MOD 1000000007;
#define PI 3.14159265358979323846;
using namespace std;
typedef long long ll;
ll mod = 1000000007;

int main()
{
	int N;
	cin >> N;

	ll S[200001];
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}
	for (int i = 0; i < N; i++)
	{
		S[i + 1] = S[i + 1] + S[i];
	}

	ll minValue = 1000000000000;
	for (int i = 0; i < N - 1; i++) {
		ll x = S[i];
		ll y = S[N - 1] - S[i];

		minValue = min(minValue, abs(x - y));
	}

	cout << minValue << endl;

	return 0;
}