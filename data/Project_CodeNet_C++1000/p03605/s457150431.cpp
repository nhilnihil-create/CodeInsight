#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
long long n;
int main()
{
	cin>>n;
	while(n>0)
	{
		if(n%10==9)
		{
			cout<<"Yes";
			return 0;
		}
		n/=10;
	}
	cout<<"No";
    return 0;
}