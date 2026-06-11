#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int i,n,s,j,f=0;
 	string w;
 	cin>>w;
 	int l=w.length();
 	int v[200]={0};
 //	vector<int>v;
 //	v.assign(l,0);
 	for(i=0;i<l;i++)
 	{
 		for(j=97;j<=122;j++)
 			{
 				if(w[i]==j)
 					v[j]++;
			 }
	 }
	 for(i=97;i<123;i++)
	 	{
	 		if(v[i]%2!=0)
	 		{
	 			f=1;
	 			break;
			 }
		 }
		 if(f==0)
			 cout<<"Yes"<<endl;
		 else
		 	cout<<"No"<<endl;
 }