#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
int main(){
	fast;
	ll h,w,n,cnt=0;
	cin>>h>>w>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<arr[i];j++)
			v.push_back(i+1);
	}
	int mat[h][w];
	for(int i=0;i<h;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<w;j++)
				mat[i][j]=v[cnt],cnt++;
		}
		else
		{
			for(int j=w-1;j>=0;j--)
				mat[i][j]=v[cnt],cnt++;
		}
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}