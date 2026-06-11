#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a;
	int l=a.size();
	b=a;
	for(int i=0;i<l;i++)
		switch(b[i])
		{
			case 'b':
				b[i]='d';
				break;
			case 'd':
				b[i]='b';
				break;
			case 'q':
				b[i]='p';
				break;
			case 'p':
				b[i]='q';
				break;
		}
	
	for(int i=0;i<l;i++)
		if(a[i]!=b[l-1-i])
		{
			cout<<"No";
			return 0;
		}
	
	cout<<"Yes";
	return 0;
}