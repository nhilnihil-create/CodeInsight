#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t;
	cin>>n>>t;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	int mx=0,deltamx=0;
	int ans=0;
	for(int i=n-1;i>=0;i--){
		if(mx){
			if(a[i]<mx){
				int d=mx-a[i];
				if(d>deltamx){
					deltamx=d;
					ans=1;
				}
				else if(d==deltamx) ans++;
			}
		}
		mx=max(mx,a[i]);
	}
	cout<<ans<<endl;
}