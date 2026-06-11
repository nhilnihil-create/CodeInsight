#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define long long LL     
#define MAXN=1e4+10    


int main(){
	int a,b,c;
	int ans=0;
	cin>>a>>b>>c;
	if(a+b==c || a+c==b || b+c==a){
		ans=1;
	}
	if(ans==1){
		cout<<"Yes"<<endl;
	}else if(ans==0){
		cout<<"No"<<endl;
	}
	return 0;
}