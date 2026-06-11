#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000000];
int main(){
	int n;
	cin>>n>>s;
	s=s+s;
	for(int i=0;i<2;i++)
	for(int j=0;j<2;j++){
		a[0]=i;
		a[1]=j;
		for(int k=2;k<n+2;k++){
			if(s[k-1]=='o'&&a[k-1]==0)
			a[k]=1-a[k-2];
			if(s[k-1]=='o'&&a[k-1]==1)
			a[k]=a[k-2];
			if(s[k-1]=='x'&&a[k-1]==0)
			a[k]=a[k-2];
			if(s[k-1]=='x'&&a[k-1]==1)
			a[k]=1-a[k-2];
		}
		if(a[n]==a[0]&&a[n+1]==a[1]){
			for(int k=0;k<n;k++)
			cout<<(a[k]?'S':'W');
			return 0;
		}
	}
	cout<<-1;
	return 0;
}