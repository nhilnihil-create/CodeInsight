
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    long long flag=0;
    for(int i=0; i<s.size(); i++)
    {
		long long a=0;
		for(int j=0; j<s.size(); j++)
		{
			if(s[i]==s[j])
			{
				a++;
			}
		}
		if(a%2==0)
		{
			flag=1;
		}
		else 
		{
			flag=0;
			break;
		}
	}
	
	
	if(flag==1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
    
    return 0;
}
