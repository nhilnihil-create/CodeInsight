#include <bits/stdc++.h>
using namespace std;
string a;
int main()
{
	cin>>a;
	int l=a.size();
	if(a[0]==a[l-1])
		if(l&1) printf("Second\n");
		else printf("First\n");
	else 
		if(l&1) printf("First\n");
		else printf("Second\n");
	return 0;
}