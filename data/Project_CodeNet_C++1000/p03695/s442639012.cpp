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
	ll n;
	cin>>n;
	int arr[n],col[9]={0},minV=0,maxV=0,flag=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]>3199)
			col[8]++;
		else
			col[arr[i]/400]++;
	}
	for(int i=0;i<8;i++)
		if(col[i])
			minV++;
	if(minV==0)
			cout<<minV+1<<" "<<minV+col[8];		
	else
			cout<<minV<<" "<<minV+col[8];

	return 0;
}

