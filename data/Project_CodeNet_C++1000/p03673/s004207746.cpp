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
#define mod 1000000007
int main(){
	fast;
	ll n;
	cin>>n;
	ll arr[n];
	vector <int> ans;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(ll i=0;i<n;i++)
	{
		if(n%2 == 0)
			if(i%2 != 0)
				ans.insert(ans.begin(), arr[i]);
			else
				ans.push_back(arr[i]);
		else
			if(i%2 == 0)
				ans.insert(ans.begin(), arr[i]);
			else
				ans.push_back(arr[i]);
 
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

