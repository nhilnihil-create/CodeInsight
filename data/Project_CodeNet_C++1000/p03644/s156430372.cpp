#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<cmath>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
using namespace std;
 
int main()
{
int n,i; cin >> n;
	for ( i = 1;; i *= 2)
	{
		if (i * 2 > n)
			break;
	}
	cout << i;
return 0;
}