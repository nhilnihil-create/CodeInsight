#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;
string st="CODEFESTIVAL2016",st1;
int h;
int main()
{
	cin>>st1;
	for(int i=0;i<16;i++)
	{
		if(st[i]!=st1[i])h++;
	}
	cout<<h<<endl;
	return 0;
}