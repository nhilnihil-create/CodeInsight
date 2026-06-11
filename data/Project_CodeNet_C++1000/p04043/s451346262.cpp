#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
   
	int a, b, c;
	cin >> a >> b >> c;

	if((a==5&&b==5&&c==7) || (a==5&&b==7&&c==5) || (a==7&&b==5&&c==5))
		cout << "YES";
	else
		cout << "NO";
	
	return 0;

}
