#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int a[100005];
int main(){
	int n,t;
	cin>>n>>t;
	for(int i=0;i<n;i++) cin>>a[i];
	int maxn=-0x3f3f3f3f,temp=-0x3f3f3f3f;
	for(int i=n-1;i>=0;i--){
		temp=max(temp,a[i]);
		maxn=max(maxn,temp-a[i]);
	}
	temp=-0x3f3f3f3f;
	int cnt=0;
	for(int i=n-1;i>=0;i--){
		temp=max(a[i],temp);
		if(temp-a[i]==maxn){
			cnt++;
		}
	}
	//if(cnt<=t/2) cout<<cnt<<endl;
	//else cout<<t/2<<endl;
	cout<<cnt<<endl; 
} 