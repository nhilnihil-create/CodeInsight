#include<bits/stdc++.h>
using namespace std;
int n,m,js,js1,js2;
int a[110];
vector<int>ans;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		if(a[i]&1){
			if(js1)js2=a[i];
			else js1=a[i];
			js++;
		}	
		else ans.push_back(a[i]);
	}
	if(js>2){
		cout<<"Impossible"<<endl;
		return 0;
	}
	if(n==1){
		cout<<1<<endl;
		cout<<1<<endl;
		cout<<1<<endl;
		return 0; 
	}
	if(m==1){
		cout<<n<<endl;
		cout<<2<<endl;
		cout<<1<<" "<<n-1<<endl;
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(a[i]&1){
			if(i==1||i==m)continue;
			if(a[1]%2==0){
				swap(a[i],a[1]);
			}
			else if(a[m]%2==0){
				swap(a[i],a[m]);
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<a[i]<<" ";
	a[1]++;a[m]--;
	cout<<endl;
	if(a[m]==0)m--;
	cout<<m<<endl;
	for(int i=1;i<=m;i++)cout<<a[i]<<" ";
	return 0;
}
/*
*/