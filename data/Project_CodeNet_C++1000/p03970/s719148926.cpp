#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
char a[20]={"CODEFESTIVAL2016"},x[500];
int m;
int main()
{
	int sum=strlen(a);
	for(int i=0;i<sum;i++)
	{
		cin>>x[i];
		if(x[i]!=a[i]) m++;
	}
	cout<<m;
	return 0;
}
