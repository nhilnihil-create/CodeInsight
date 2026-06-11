#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
#define PI 3.14159265358979323846264338327950L
typedef long long ll;
using namespace std;
const int MAX = 0x7ffffff;
int t;

void slove()
{
	string s;cin >> s;
	int n = s.size();
	n = n - 2;
	while(n)
	{
		string l = s.substr(0 , n / 2);
		string r = s.substr(n / 2 , n - n / 2);
		if(l == r)
		{
			cout << n << endl;
			return;
		}
		n -= 2;
	}
}
int main()
{
	SIS;
	slove();
}