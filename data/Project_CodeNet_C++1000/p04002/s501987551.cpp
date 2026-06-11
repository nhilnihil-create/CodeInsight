#include "bits/stdc++.h"
using namespace std;

int main(){
	long long int h,w,n;
	cin>>h>>w>>n;
	
	map<int,map<int,int> > mp;
	
	vector<int> a(n);
	vector<int> b(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		mp[a[i]][b[i]]++;
	}
	
	int tmp;
	
	map<int,map<int,int> > used;
	
	int x[]={-1,-1,-1,0,0,0,1,1,1};
	int y[]={-1,0,1,-1,0,1,-1,0,1};
	
	vector<int> ans(10,0);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<9;j++){
			if(used[a[i]+x[j]][b[i]+y[j]]==0
				&&a[i]+x[j]>1
				&&b[i]+y[j]>1
				&&a[i]+x[j]<h
				&&b[i]+y[j]<w
			){
				tmp=0;
				for(int k=0;k<9;k++){
					tmp+=mp[a[i]+x[j]+x[k]][b[i]+y[j]+y[k]];
				}
				ans[tmp]++;
				used[a[i]+x[j]][b[i]+y[j]]=1;
			}
		}
	}
	
	long long int sum=0;
	for(int i=0;i<10;i++)sum+=ans[i];
	cout<<(h-2)*(w-2)-sum<<endl;
	for(int i=1;i<10;i++)cout<<ans[i]<<endl;
	
	return 0;
}