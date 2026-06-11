#include <bits/stdc++.h>
using namespace std;

int main () {
	int x,y,n,m;
	
	cin>>x>>y>>n>>m;
	
	int has = x-y;
	
	if(has <=0 ) {
		cout<<n*x<<endl;
	} else {
		cout<<y*n + has*m<<endl;
	}
}