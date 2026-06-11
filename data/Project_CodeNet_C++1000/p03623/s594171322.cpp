#include<bits/stdc++.h>
using namespace std;

int x, b, a;
 
int main()
{
	ios::sync_with_stdio(false);
	cin >> x >> a >> b;
	if (abs(x - a) < abs(x - b)) cout << "A" << endl;
	else cout << 'B' << endl;
	   
	return 0;
}
