#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,a,b;
    cin>>n>>a>>b;
	if(n == 1){
		if(a!=b)cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	if(a>b){
		cout<<0<<endl;
		return 0;
	}
	cout<<(b*(n-1)+a)-((a*(n-1))+b)+1<<endl;
}