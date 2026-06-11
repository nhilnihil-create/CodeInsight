//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
using namespace std;
int a,b,x;
int main()
{
	cin>>x>>a>>b;
	if(abs(x-a)<abs(x-b))
		cout<<"A\n";
	else if(abs(x-a)>abs(x-b))
		cout<<"B\n";
		

	
	
	

	return 0;
}

