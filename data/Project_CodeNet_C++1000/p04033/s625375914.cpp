#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979

int main()
{
	ll a, b;
	cin >> a >> b;
	if (b >= 0 && a <= 0)                            cout << "Zero" << endl;
	else if (a > 0 && b > 0 || (b - a + 1) % 2 == 0) cout << "Positive" << endl;
	else			                                 cout << "Negative" << endl;
	return 0;
}