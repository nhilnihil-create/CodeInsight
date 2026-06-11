#include<bits/stdc++.h>
#define rint register int
#define ll long long 
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;
	if(a<=0&&b>=0) {
		cout<<"Zero";
		exit(0);
	}
	if(a>0) {
		cout<<"Positive";
		exit(0);
	}
	int cnt=b-a+1;
	if(cnt&1) cout<<"Negative";
	else cout<<"Positive"; 
	return 0;
} 