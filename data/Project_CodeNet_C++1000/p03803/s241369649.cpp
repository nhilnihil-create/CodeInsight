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
	int a,b;
	cin>>a>>b;
	if(a==b)
		cout<<"Draw"<<endl;
	else if(b==1)
		cout<<"Bob"<<endl;
	else if(a==1)
		cout<<"Alice"<<endl;
	else
		a>b?cout<<"Alice":cout<<"Bob";
	return 0;
}