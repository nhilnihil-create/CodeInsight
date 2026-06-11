#include<iostream>
using namespace std;
int H,W,h,w;
int A[500][500];
main()
{
	cin>>H>>W>>h>>w;
	if(h*w==1)
	{
		cout<<"No"<<endl;
		return 0;
	}
	int cnt=0;
	for(int i=h-1;i<H;i+=h)for(int j=w-1;j<W;j+=w)A[i][j]=-1,cnt++;
	long a=(1e9-1)/(h*w-1),b=1e9;
	if(a*(H*W-cnt)>b*cnt&&b*cnt>a*cnt*(h*w-1))
	{
		cout<<"Yes"<<endl;
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)cout<<(A[i][j]<0?-b:a)<<(j==W-1?"\n":" ");
		}
	}
	else cout<<"No"<<endl;
}