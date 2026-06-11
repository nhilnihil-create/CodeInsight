#include<bits/stdc++.h>
using namespace std;

int x[501],a[250001];
vector<int> l[501],r[501];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i],a[x[i]]=i;
	set<int> st;
	for(int i=1;i<=n;i++)
		st.insert(x[i]);
	for(int i=1;i<=n*n;i++){
		if(st.count(i))	continue;
		int z=-1;
		for(int j=1;j<=n;j++)
			if((int)l[j].size()<=j-2&&i<x[j])
				if(z==-1||x[j]<x[z])
					z=j;
		if(z!=-1){
			l[z].emplace_back(i);
			continue;
		}
		for(int j=1;j<=n;j++)
			if((int)r[j].size()<=n-j-1&&i>x[j])
				z=j;
		if(z==-1){
			cout<<"No"<<endl;
			return 0;
		}
		r[z].emplace_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int it:l[i])
			a[it]=i;
		for(int it:r[i])
			a[it]=i;
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=n*n;i++)
		cout<<a[i]<<' ';
	cout<<endl;
}
