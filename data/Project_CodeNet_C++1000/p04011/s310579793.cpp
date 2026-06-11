#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int MOD = 1000000007;
int main()
{
	int a, b , c, d;
	cin >> a >> b >> c >> d;
	
	if(a < b) cout << a*c << endl;
	else cout << (b*c)+(a-b)*d << endl; 
	
	
	
	return 0;
}