#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>
#include <bitset>
#include <cmath>
#include <stack>
#include <iomanip>
#include <map>
#include <math.h>
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int MOD = 1000000007;
const ll INF = 1LL << 60;

ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) {return a / GCD(a, b) * b;}

int main()
{
	int N;
	cin >> N;
	int a;
	int count4 = 0;
	int count2 = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> a;
		if(a % 4 == 0) count4++;
		if(a % 4 != 0 && a % 2 == 0) count2++;
	}
	if((count2 == 0 && count4 * 2 + 1 >= N )|| (count2 != 0 && count4 * 2 + count2 >= N))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

}
