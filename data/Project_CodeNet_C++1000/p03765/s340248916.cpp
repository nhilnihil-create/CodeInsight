#include<bits/stdc++.h>
using namespace std;

signed main()
{
	string strA, strB;
	int arrA[1000000], arrB[1000000];
	cin >> strA >> strB;
	arrA[0] = 0;
	arrB[0] = 0;
	for(int j = 0;j<=strA.length();j++)
	{
		if(strA[j]=='A') arrA[j+1] = arrA[j] + 1;
		else arrA[j+1] = arrA[j] + 2;
//		cout << arrA[j+1] << " ";
	}
	for(int j = 0;j<=strB.length();j++)
	{
		if(strB[j]=='A') arrB[j+1] = arrB[j] + 1;
		else arrB[j+1] = arrB[j] + 2;
	}
	int t; cin >> t;
	while(t--)
	{
		int a, b, c, d; cin >> a >> b >> c >> d;
		int suma = 0, sumb = 0;
		suma = arrA[b] - arrA[a-1];
		sumb = arrB[d] - arrB[c-1];
		suma %= 3; sumb %= 3;
		if(suma==sumb) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}