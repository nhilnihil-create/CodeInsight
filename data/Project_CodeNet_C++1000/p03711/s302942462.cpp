#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int a[15],n,m;
	for(int i=1;i<=7;i++)
	{
		if(i==2)a[i]=3;	
		else if(i%2)a[i]=1;
		else a[i]=2;
	}
	for(int i=8;i<=12;i++)
	{
		if(i%2)a[i]=2;
		else a[i]=1;
	}
	cin>>n>>m;
	if(a[n]==a[m])cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}