#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
int main(){
	fast;
	ll h,w;
	cin>>h>>w;
	char arr[h][w];
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			cin>>arr[i][j];
	for(int i=0;i<h;i++)
	{
				for(int j=0;j<w;j++)
			cout<<arr[i][j];
			cout<<endl;
					for(int j=0;j<w;j++)
			cout<<arr[i][j];
			cout<<endl;
	}
	return 0;
}

