#include<iostream>
#include<iomanip>
#include<limits>
#include<string>
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include <functional>

#define big ((long long)(1e9)+7)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
	ll n,a,b;
	cin >> n >> a >> b;
	if(a > b)
	{
		cout << 0 << endl;
		return 0;
	}
	else if(n == 1)
	{
		if(a == b)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 0 << endl;
		}
	}
	else
	{
		cout << (b-a)*(n-2)+1 << endl;
	}
}
