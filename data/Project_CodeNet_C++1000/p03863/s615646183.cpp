#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x)
{
	T ll=1;
    T res=0;
	char ch=getchar();
    while(!isdigit(ch))
    {
		if(ch=='-')
		ll=-1;
		ch=getchar();
	}
    while(isdigit(ch))
	res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
    x=res*ll;
}
template<typename T>void print(T x)
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
int main()
{
	string s;
	cin>>s;
	int len=s.length();
	if(s[0]==s[len-1])
	{
		if(len%2==0)
		{
			puts("First");
		}
		else
		{
			puts("Second");
		}
	}
	else
	{
		if(len%2==0)
		{
			puts("Second");
		}
		else
		{
			puts("First");
		}
	}
}