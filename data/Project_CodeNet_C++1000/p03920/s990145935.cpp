#include<iostream>
using namespace std;
int n;
int main(){
	cin>>n;int t=0;
	for(int i=5000;i>=0;i--){
		int c=i*(i+1)/2;
		if(c<n){t=i+1;break;}
	}
	for(int i=t;i>=1;i--){
		if(n>=i){cout<<i<<endl;n-=i;}
	}
	return 0;
}