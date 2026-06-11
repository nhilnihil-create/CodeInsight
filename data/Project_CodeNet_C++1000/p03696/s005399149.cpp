#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char str[N];
int cut1,cut2,n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>str[i];
	for(int i=1;i<=n;i++)
	{
		if(str[i]=='(')	cut1++;
		if(str[i]==')')
		{
			cut1--;
			if(cut1<0) cut2++,cut1 = 0;
		}
	}
	for(int i=1;i<=cut2;i++)
		cout<<"(";
	for(int i=1;i<=n;i++)
		cout<<str[i];
	for(int i=1;i<=cut1;i++)
		cout<<")";
	cout<<"\n";
}