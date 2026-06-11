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
	ll A[3];
	cin >> A[0] >> A[1] >> A[2];
	sort(A, A + 3);
	if (A[0] % 2 == 0 || A[1] % 2 == 0 || A[2] % 2 == 0) {
		cout << 0 << endl;
	}
	else {
		cout << A[0] * A[1] << endl;
	}
}