#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    long long res=0;
	char ch=getchar();
    while(!isdigit(ch))
	ch=getchar();
    while(isdigit(ch))
	res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    return res;
}
void print(int x)
{
    if(x<0)putchar('-'),x=-x;
    if(x<10)
    putchar(x+'0');
    else
    {
        print(x/10);
        putchar(x%10+'0');
    }
}
string reverse(string x)
{
	string ans;
	for(int k=x.length()-1;k>=0;k--)
	{
		ans+=x[k];
	}
	return ans;
}
string hhh(string x)
{
	string ans;
	for(int k=0;k<x.length();k++)
	{
		switch(x[k])
		{
			case 'b':
			{
				ans+='d';
				break;
			}
			case 'd':
			{
				ans+='b';
				break;
			}
			case 'p':
			{
				ans+='q';
				break;
			}
			case 'q':
			{
				ans+='p';
				break;
			}
		}
	}
	return ans;
}
int main()
{
	string s;
	cin>>s;
	if(s==hhh(reverse(s)))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	return 0;
}
