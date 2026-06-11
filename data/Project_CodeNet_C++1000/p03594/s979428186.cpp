#include<iostream>
using namespace std;
int h,w,d;
char a[4]={'R','Y','G','B'};
int main()
{
	cin>>h>>w>>d;
	for(int i=1;i<=h;++i,cout<<endl)
	for(int j=1;j<=w;++j)
	{
		int x=i+j+w,y=i-j+w;
		cout<<a[((x/d)&1)*2+((y/d)&1)];
	}
	return 0;
}
 