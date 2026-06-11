#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define elif else if
string a;
signed main()
{
	cin>>a;
	rep(i,4){
		cout<<a[i];
	}
	cout<<" ";
	rep(i,8){
		cout<<a[i+4];
	}
	cout<<endl;
}