#include<bits/stdc++.h>
using namespace std;
long long n,m,i,j,sum,ans;
string a,b,c;
int main()
{
    cin>>a;
    for(i=0;i<a.size();i++) 
	   b=a[i]+b;
    for(i=0;i<a.size();i++)
    {
        if(a[i]=='b')
          a[i]='d';
    	else
          if(a[i]=='d')
            a[i]='b';
          else
            if(a[i]=='p')
              a[i]='q';
            else 
              if(a[i]=='q')
                a[i]='p';      
    }
    if(a==b)
    {
        cout<<"Yes";
    }
    else
        cout<<"No";
    return 0;
}