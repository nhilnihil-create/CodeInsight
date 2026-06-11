#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	string s;
	int n;
	int ans=0,mx=INT_MIN;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='I')
			ans++;
		else
			ans--;
		if(ans>mx)
			mx=ans;
	}
	cout<<max(mx,0);
	return 0;
}

