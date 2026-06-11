#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb push_back
#define bg begin()
#define end end()
#define sz size()
#define vi vector<int>
#define vl vector<long long int>
int main(){
	fast;
	ll x,y;
	cin>>x>>y;
	if(x==2||y==2)
	{
		cout<<"No";
		return 0;
	}
	if(x==1||x==3||x==5||x==7||x==8||x==10||x==12)
		if(y==1||y==3||y==5||y==7||y==8||y==10||y==12)
			{
				cout<<"Yes";
				return 0;
			}
		else
		{
		cout<<"No";
		return 0;
		}
	else
		if(y==4||y==6||y==9||y==11)
			{
				cout<<"Yes";
				return 0;
			}
		else
		{
		cout<<"No";
		return 0;
		}
		
	return 0;
}

