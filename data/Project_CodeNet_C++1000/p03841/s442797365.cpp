#include<bits/stdc++.h>
using namespace std;

const int N=600;
pair<int,int>a[N];
int b[N*N],n;
void gofail(){cout<<"No\n";exit(0);}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i].first,a[i].second=i,b[a[i].first]=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		int les=a[i].second-1;
		for(int j=1;j<a[i].first&&les;++j)
			if(!b[j])b[j]=a[i].second,--les;
		if(les)gofail();
	}
	for(int i=n;i;--i){
		int les=n-a[i].second;
		for(int j=n*n;j>a[i].first&&les;--j)
			if(!b[j])b[j]=a[i].second,--les;
		if(les)gofail();
	}
	cout<<"Yes\n";
	for(int i=1;i<=n*n;++i)
		cout<<b[i]<<" \n"[i==n*n];
	return 0;
}
