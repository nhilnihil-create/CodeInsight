#include<bits/stdc++.h>
using namespace std;
int a[15];
int num=1,len;
long long ans=0;
string s;
int main()
{
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)
		a[i+1]=(s[i]-'0');
	for(int i=1;i<len;i++)
		num*=2;
	for(int i=0;i<num;i++)
	{
		bool b[15]={0};
		int tmp=i;
		int k=1;
		while(tmp)
			b[k++]=tmp%2,tmp/=2;
		long long cn=0;
		for(int j=1;j<=len;j++)
		{
			cn=cn*10+a[j];
			if(b[j])
			{
				ans+=cn;
				cn=0;
			}
		}
		ans+=cn;
	}
	cout<<ans; 

	return 0;
}
