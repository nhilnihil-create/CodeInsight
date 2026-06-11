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
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	if (A <= C && C <= B) cout << min(B, D) - C << endl;
	else if (C <= A && A <= D) cout << min(B, D) - A << endl;
	else cout << 0 << endl;
}