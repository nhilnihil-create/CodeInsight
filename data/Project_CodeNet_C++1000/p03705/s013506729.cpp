#include<iostream>
#include<cstdio>
using namespace std;
long long n,a,b;
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>a>>b;
	if(n==1&&a!=b){
		cout<<0;
	}
	else if(a>b){
		cout<<0;
	}
	else
		cout<<(n-1)*b+a-((n-1)*a+b)+1;
	return 0;
}