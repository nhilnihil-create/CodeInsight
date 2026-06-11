#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[5],s,i;
	for (i=1;i<=3;i++) cin>>a[i];
	sort (a+1,a+3+1);
	s=s+a[1]+a[2];
	cout<<s;
	return 0;
}
