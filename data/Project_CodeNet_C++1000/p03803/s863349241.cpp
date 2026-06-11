//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int a,b;
int main()
{
	cin>>a>>b;
	if(a>b&&b!=1)
		cout<<"Alice\n";
	else if(a>b&&b==1)
		cout<<"Bob\n";
	else if(b>a&&a!=1)
		cout<<"Bob\n";
	else if(b>a&&a==1)
		cout<<"Alice\n";
	else
		cout<<"Draw\n";
	
    return 0;
 
}

