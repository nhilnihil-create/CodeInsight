#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
bool compare(int a,int b)
{
return a>b;
}
int main(){
	int n,a[100000];
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int co=0;
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			co++;
			int t=a[i];
			if(i+1<=n){
				a[i]=a[i+1];
				a[i+1]=t;
			}
			else {
				a[i]=a[i-1];
				a[i-1]=t;
			}
		}
	}
	cout<<co<<endl;
	return 0;
}