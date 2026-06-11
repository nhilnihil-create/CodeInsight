#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
using namespace std;
int main(){
	int n,b;
	cin>>n>>b;
	int a[b]={};
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	int zuida=0;
	for(int i=0;i<b;i++){
		if(a[i]>zuida)zuida=a[i];
	}
	int qita=0;
	bool flag=true;
	for(int i=0;i<b;i++){
		if(zuida==a[i]&&flag==true){
			a[i]=0;
			flag=false;
		}
		qita+=a[i];
	}
	if(qita>=zuida){
		cout<<"0";
	}else cout<<zuida-qita-1;
return 0;
}
