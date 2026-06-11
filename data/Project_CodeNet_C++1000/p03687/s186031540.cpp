#include<iostream>
using namespace std;
string s;
int ans=114514;
main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		int m=0,k=0;
		for(int j=0;j<=s.size();j++)
		{
			if(j==s.size()||s[i]==s[j])
			{
				if(m<k)m=k;
				k=0;
			}
			else
			{
				k++;
			}
		}
		if(ans>m)ans=m;
	}
	cout<<ans<<endl;
}
