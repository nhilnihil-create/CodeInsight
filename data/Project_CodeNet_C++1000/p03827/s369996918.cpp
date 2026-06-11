//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int  q,x,n;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='I')
			x++;
		else
			x--;
		q=max(q,x);
	}
	cout<<q<<"\n";

	return 0;
}

