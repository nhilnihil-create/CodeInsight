#include<bits/stdc++.h>
using namespace std;

int ans[501][501];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int H,W,h,w;
	cin>>H>>W>>h>>w;
	if(H%h==0&&W%w==0)
		return cout<<"No\n",0;
	cout<<"Yes\n";
	for(int i=1;i<=H;i+=h)
		for(int j=1;j<=W;j+=w)
			ans[i][j]=999999999;
	for(int i=h;i<=H;i+=h)
		for(int j=w;j<=W;j+=w)
			ans[i][j]=-1e9;
	for(int i=1;i<=H;i++,cout<<'\n')
		for(int j=1;j<=W;j++)
			cout<<ans[i][j]<<' ';
}
