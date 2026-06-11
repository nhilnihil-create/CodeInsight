//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
int a,b,c,q[101],countt;
int main()
{
	cin>>a>>b>>c;
	q[a]++;
	q[b]++;
	q[c]++;
	for(int i=0;i<=100;i++)
		if(q[i]!=0)
			countt++;
	cout<<countt<<"\n";

	
	


	
	
    return 0;
 
}

