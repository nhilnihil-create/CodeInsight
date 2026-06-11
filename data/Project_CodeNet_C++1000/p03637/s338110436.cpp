#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define mp make_pair
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n],b[8]={0};
	for(int i= 0; i<n; i++)
	{
		cin>>a[i];
		if(a[i]%4==0)
			b[4]++;
		else if(a[i]%2==0)
			b[2]++;
	}
	ll cnt = 2*b[4]+1;
	cnt += b[2]>0?b[2]-1:0;
	if(cnt>=n)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}