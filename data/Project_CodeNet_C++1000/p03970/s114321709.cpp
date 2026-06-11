#include<bits/stdc++.h>
using namespace std;
main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	const string p="CODEFESTIVAL2016";string a;
	int sum=0;
	getline(cin,a);
	for(int i=0;i<=15;i++)
		if(a[i]!=p[i]) sum++;
	printf("%d",sum);
	return 0;
}