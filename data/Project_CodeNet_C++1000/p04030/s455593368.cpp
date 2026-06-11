#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	int i,n;
 	string s,t;
 	cin>>s;
 	n=s.length();
 	for(i=0;i<n;i++)
 	{
 		if(s[i]=='0')
 			t.push_back('0');
 		if(s[i]=='1')
 			t.push_back('1');
 		
 		if(s[i]=='B')
 			{
 				if(t.length()>0)
				 		
 				t.pop_back();
			 }
	 }
	 cout<<t<<endl;
 }