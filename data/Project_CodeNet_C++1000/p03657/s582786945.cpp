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
	int A, B;
	cin >> A >> B;
	if (A % 3 == 0 || B % 3 == 0 || (A + B) % 3 == 0) {
		cout << "Possible" << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
}
