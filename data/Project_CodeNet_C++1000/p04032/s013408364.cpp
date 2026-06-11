#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long test=1;
// 	cin>>test;	
	while(test--)
	{
	long a,b=0,c=0,k,i,n,j,temp,mini,maxi,ans,q;
	string s;
	cin>>s;
	for(i=0;i<s.length()-1;i++)
	{
	    if(s[i]==s[i+1])
	    {
	        cout<<i+1<<" "<<i+2<<endl;
	        return 0;
	    }
	}
	for(i=0;i<s.length()-2;i++)
	{
	    if(s[i]==s[i+2])
	    {
	        cout<<i+1<<" "<<i+3<<endl;
	        return 0;
	    }
	}
	cout<<-1<<" "<<-1<<endl;
	
    }
    
}
