#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;

int main()
 {
 	string a,b,c;
 	 cin>>a>>b>>c;
 	 char cur='a';
 	int n=a.length();
 	int m=b.length();
 	int k=c.length();
 	 int x=0,y=0,z=0;
 	 while(x<=n&&y<=m&&z<=k)
 	 	{
 	 		if(cur=='a')
 	 			{
 	 			cur=a[x];
				  x++;	
				  }
			else if(cur=='b')
				{
					cur=b[y];
					y++;
			}
			else
				{
					cur=c[z];
					z++;
				}
		  }
 	if(x>n)
 		cout<<'A'<<endl;
 	else if(y>m)
 		cout<<'B'<<endl;
 	else
 		cout<<'C'<<endl;

 
     
 return 0;
 }




