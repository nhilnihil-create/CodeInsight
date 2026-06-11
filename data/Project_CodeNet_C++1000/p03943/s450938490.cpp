#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if((a+b+c)&1)cout<<"No";
	else{
		int x=(a+b+c)/2;
		if(x==a || x==b || c==x){
			cout<<"Yes";
		}
		else cout<<"No";
	}
}