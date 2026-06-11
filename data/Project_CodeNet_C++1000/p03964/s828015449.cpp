#include <bits/stdc++.h>
using namespace std;
long long ceil1(long long a,long long b)
{
	if(a % b == 0)
		return a / b;
	else
		return a / b + 1;
}
 
void solve(int n)
{
	long long a = 1, b = 1;
	for(long long i = 0; i < n; i++)
	{
		long long x , y;
		cin >> x >> y;
		long long temp = max (ceil1(a,x),ceil1(b,y));
		a = temp * x;
		b = temp * y;
	}
	cout << a+b;
	return;
}
int main() {
	int n;
	cin >> n;
	solve(n);
}