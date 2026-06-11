#include<bits/stdc++.h>
using namespace std;
long long x,y;
int main()
{
	cin>>x>>y;
	if(x-y>=-1&&x-y<=1)	puts("Brown");
	else	puts("Alice");
	return 0;
}