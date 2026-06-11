#include<bits/stdc++.h>
using namespace std;
string a[3];
int x[3],zhi=0;
int main()
{
	cin>>a[0]>>a[1]>>a[2];
	while(a[zhi].size()!=x[zhi])
	{
		switch(a[zhi][x[zhi]])
		{
			case 'a':
				{
					x[zhi]++;
					zhi=0;
					break;
				}
			case 'b':
				{
					x[zhi]++;
					zhi=1;
					break;
				}
			case 'c':
				{
					x[zhi]++;
					zhi=2;
					break;
				}
		}
	}
	if(zhi==0) cout<<"A";
	else if(zhi==1) cout<<"B";
	else cout<<"C";
}