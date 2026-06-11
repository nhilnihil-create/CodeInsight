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
	ll h,w;
	cin>>h>>w;
	char arr[h+2][w+2];
	for(int i=0;i<h+2;i++)
		for(int j=0;j<w+2;j++)
			arr[i][j]='#';
	for(int i=1;i<h+1;i++)
		for(int j=1;j<w+1;j++)
			cin>>arr[i][j];
	for(int i=0;i<h+2;i++)
	{
		for(int j=0;j<w+2;j++)
			cout<<arr[i][j];
		cout<<endl;
	}
	return 0;
}

