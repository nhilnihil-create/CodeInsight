#include<bits/stdc++.h>
#define N 505
using namespace std;

inline bool rd(int &X)
{
    X=0;int w=0;char ch=0;
    while(!isdigit(ch))w|=ch=='-',ch=getchar();
    while( isdigit(ch))X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
    X=w?-X:X; return 1;
}

int n,m,d;
char s[]={"RGBY"};
signed main()
{
    cin>>n>>m>>d;
		for(int i=0;i<n;i++,cout<<endl)
			for(int j=0;j<m;j++)
			{
				int x=(m+i+j)/d&1;
				int y=(m+i-j)/d&1;
				putchar(s[2*x+y]);
			}
}
