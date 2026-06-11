#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long


int main()
{
	int N;
	cin >> N;
	int ans = 1;
	while (ans * 2 <= N) {
		ans *= 2;
	}
	cout << ans << endl;
}
