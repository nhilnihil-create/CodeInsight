#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;
#define ll long long int

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n,a,temp;
	cin>>n>>a;
	ll arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	temp=-1;
	for (int i = 0; i < n-1; ++i)
	{
		if(arr[i]+arr[i+1]>=a){
			temp=i+1;
			break;
		}
	}
	if(temp>0){
		cout<<"Possible"<<endl;
		for (int i = 1; i < temp; ++i)
		{
			cout<<i<<endl;
		}
		for (int i = n-1; i > temp; --i)
		{
			cout<<i<<endl;
		}
		cout<<temp<<endl;
	}
	else{
		cout<<"Impossible"<<endl;
	}
	return 0;
}
