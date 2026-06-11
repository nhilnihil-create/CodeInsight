#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
 
int main(){
	int H,W,n,mean=0;
	cin>>H>>W;
	string A[100];
	for(int i=0;i<H;i++)cin>>A[i];
	for(int i=0;i<W+2;i++)cout<<"#";
	cout<<endl;
	for(int i=0;i<H;i++)cout<<"#"<<A[i]<<"#"<<endl;
	for(int i=0;i<W+2;i++)cout<<"#";
	cout<<endl;
}