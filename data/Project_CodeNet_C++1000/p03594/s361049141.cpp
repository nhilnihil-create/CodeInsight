#include<bits/stdc++.h>
using namespace std;
#define re register
#define ll long long
#define in inline
#define get getchar()
in int read()
{
	int t=0; char ch=get;
	while(ch<'0' || ch>'9') ch=get;
	while(ch<='9' && ch>='0') t=t*10+ch-'0', ch=get;
	return t;
}
int h,w,d;
char s[4]={'R','Y','G','B'};
int main()
{
	h=read();
	w=read();
	d=read();
	for(re int i=1;i<=h;i++){
		for(re int j=1;j<=w;j++)
		{
			int x=(i+j+w)/d,y=(i-j+w)/d;
			//cout<<x<<' '<<y<<endl;
			cout<<s[(x%2)*2+y%2];
		}
		cout<<endl;
	}
}
