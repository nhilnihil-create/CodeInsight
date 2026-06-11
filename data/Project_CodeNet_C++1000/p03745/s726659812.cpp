#include<bits/stdc++.h>
using namespace std;
long long n,x,a=0,num=0,f;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(a==0){
			a=x;f=0;num++;
		}
		else if(f==0){
			if(x>a)f=1;
			else if(x<a)f=-1;
			a=x;
		}
		else if(f==1){
			if(x<a){f=0;num++;}
			a=x;
		}
		else if(f==-1){
			if(x>a){f=0;num++;}
			a=x;
		}
	}
	cout<<num<<endl;	
}