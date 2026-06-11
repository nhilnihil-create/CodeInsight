#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
int main(){
	cin>>n>>m;
	if(n*2<=m)s=n+(m-2*n)/4;
	else s=m/2;
	cout<<s<<endl;
}