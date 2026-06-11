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
#include <list>
#include <deque>
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
	int N,M;
	cin >> N;
	int a;
	vector<bool> color(9,false);
	int saikyo = 0;
	for(int i = 0; i < N; i++)
	{
		cin >> a;
		if(1 <= a && a <= 399) color[0] = true;
		if(400 <= a && a <= 799) color[1] = true;
		if(800 <= a && a <= 1199) color[2] = true;
		if(1200 <= a && a <= 1599) color[3] = true;
		if(1600 <= a && a <= 1999) color[4] = true;
		if(2000 <= a && a <= 2399) color[5] = true;
		if(2400 <= a && a <= 2799) color[6] = true;
		if(2800 <= a && a <= 3199) color[7] = true;
		if(a >= 3200) color[8] = true,saikyo++;
	}
	int min = 0;
	int max = 0;
	for(int i = 0; i < 8; i++)
	{
		if(color[i]) min++;
	}
	if(color[8]) max = min+saikyo;
	else max = min;
	if(min ==0 && color[8]) min = 1,max = saikyo;
	cout << min << " " << max << endl;
}
