#include<iostream>
using namespace std;
#include<cmath>
#define int long long int
int answer=0;
int32_t main()
{
    string str;
    cin>>str;
    int k;
    cin>>k;
    int l=str.size();
    int j;
    for(j=0;str[j]!='\0';j++)
    {
		if(k==0)
		    break;
		if(str[j]=='a')
		   continue;
		else  if(str[j]=='z')
		{
			str[j]='a';
			k--;
		}
		else
		{
			int diff='z'-str[j];
			if(k>=diff+1)
			{
				str[j]='a';
				k-=(diff+1);
			}
			else
			{
				continue;
			}
		}
	}
	if(k==0)
	{
		cout<<str<<endl;
	}
	else
	{
		k=k%26;
		while(k!=0)
		{
			if(str[l-1]=='z')
			{
				str[l-1]='a';
				k--;
			}
			else
			{
				str[l-1]=(char)(str[l-1]+1);
				k--;
			}
		}
		cout<<str<<endl;
	}
}
