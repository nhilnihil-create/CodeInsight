#include<bits/stdc++.h>
using namespace std;
int n,s,q,a[100005],b[100005][20];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>s;
	int dem=1,sum=0;
	for(int i=2;i<=n;i++){
		sum+=a[i]-a[i-1];
		while(sum>s){
			b[dem][0]=i-1;
			dem++;
			sum-=(a[dem]-a[dem-1]);
		}
	}
	for(int i=dem;i<=n;i++) b[i][0]=n;
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i<=n;i++)
			b[i][j]=b[b[i][j-1]][j-1];
			
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		if(l>r) swap(l,r);
		int ans=1;
		for(int i=log2(n);i>=0;i--){
			if(b[l][i]<r){
				l=b[l][i];
				ans+=(1<<i);
			}
		}
		cout<<ans<<endl;
	}
}