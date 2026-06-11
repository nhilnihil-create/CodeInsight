#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int n,l,i,j;
 	cin>>n>>l;
 	string s[n],s2,s1;
 	s2.clear();
 	for(i=0;i<n;i++)
 		cin>>s[i];
 	for(i=0;i<n-1;i++)
 		{
 			for(j=i+1;j<n;j++)
 				{
 					if(s[i]>s[j])
 						{
 							 s1=s[i];
 							s[i]=s[j];
 							s[j]=s1;
						 }
				 }
		 }
		for(i=0;i<n;i++)
		{
			s2=s2+s[i];
		}
		cout<<s2<<endl;
 	}