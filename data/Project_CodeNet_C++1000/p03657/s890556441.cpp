//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int  a,b;
int main()
{
	cin>>a>>b;
	if((a+b)%3==0||a%3==0||b%3==0)
		cout<<"Possible\n";
	else
		cout<<"Impossible\n";


	return 0;
}

