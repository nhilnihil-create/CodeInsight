#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int ss[2005][2005];
int t[2005];

int make(int n,int x){
	int s[2005];
	int i;
	memset(s,0,sizeof(s));
	for(i=1;i<x;i++){
		s[i]=2005;
	}
	for(i=x;i<=n;i++){
		s[i]=s[i-x]-1;
	}
	for(i=0;i<n;i++){
		t[i]=s[i+1]-s[i];
	}
}

int main(){
	int a,b,c,d;
	int x,y;
	int n,m;
	int i,j,k;
	cin>>n>>m>>x>>y;
	if(n%x==0 && m%y==0){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	if(n%x!=0)make(n,x);
	else make(m,y);
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d%c",(n%x!=0)?t[i]:t[j],(j==m-1)?'\n':' ');
		}
	}
	return 0;
	
}
