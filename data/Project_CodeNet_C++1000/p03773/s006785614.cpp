//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
using namespace std;
int a,b,ans;
int main()
{
	cin>>a>>b;
	ans=a+b;
	if(b==0)
		cout<<a<<"\n";
		
	else if(ans>23)
		cout<<ans-24<<"\n";

	else
		cout<<ans<<"\n";
		

	
	
	

	return 0;
}

