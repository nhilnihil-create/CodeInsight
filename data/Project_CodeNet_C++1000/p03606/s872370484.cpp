#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int main(){
	fast;
	ll n;
	cin>>n;
	ll sum=0,l,m;
	for(int i=0;i<n;i++)
	{
		cin>>l>>m;
		sum+=(m-l+1);
	}
	cout<<sum;
	return 0;
}
