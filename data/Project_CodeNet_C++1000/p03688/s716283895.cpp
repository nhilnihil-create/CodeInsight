#include<bits/stdc++.h>
 using namespace std;
 int main(){
 	int n,a[100010],maxa=0,mina=1e9,num1=0;
 	cin>>n;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		if(a[i]>maxa) maxa=a[i];
 		if(a[i]<mina) mina=a[i];
	 }
	if(maxa-mina>1){
		cout<<"No";
		return 0;
	}
	for(int i=1;i<=n;i++)
	  if(a[i]==mina) num1++;
	if(maxa-mina==0){
		if(maxa==n-1||maxa*2<=n) cout<<"Yes";
		else cout<<"No";
	}
	else{
		if(num1<maxa&&n-num1>=2*(maxa-num1)) cout<<"Yes";
		else cout<<"No";
	}
	return 0;
 }