#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	ll a,b;
	cin>>a>>b;
	if(a==b)
	{
		cout<<"Draw";
		return 0;
	}
	if(a==1)
	{
		cout<<"Alice";
		return 0;
	}
	if(b==1)
	{
		cout<<"Bob";
		return 0;
	}
	if(a>b)
		cout<<"Alice";
	else
		cout<<"Bob";
	
	return 0;
	
}

