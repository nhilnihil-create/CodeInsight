#include<bits/stdc++.h>

using namespace std;

inline long long read()
{
	long long f = 1,x = 0;
	char ch;
	do
	{
		ch = getchar();
		if(ch == '-') f = -1;
	}while(ch < '0' || ch > '9');
	do
	{
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}while(ch >= '0'&&ch <= '9');
	return f*x;
} 

long long n,x;

int main()
{
	n = read(),x = read();
	long long ans = n - __gcd(n-x , x);
	cout << 3 * ans << endl;
}