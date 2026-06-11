//#include "stdafx.h"
#include<bits/stdc++.h> 
#include<iostream>
#include<queue>
#include<string>
using namespace std;
int a[7]={1,3,5,7,8,10,12},b[4]={4,6,9,11},c[1]={2},x,y,f,q,p,v;
int main()
{
	cin>>x>>y;
	if(x==2||y==2)
		cout<<"No\n";
	else{
		for(int i=0;i<7;i++){
			if(x==a[i])
				f=1;
			if(y==a[i])
				q=1;
		}
		for(int i=0;i<4;i++){
			if(x==b[i])
				p=1;
			if(y==b[i])
				v=1;
		}
		if((q==1&&f==1)||(p==1&&v==1))
			cout<<"Yes\n";
		else
			cout<<"No\n";

	}

	return 0;
}

