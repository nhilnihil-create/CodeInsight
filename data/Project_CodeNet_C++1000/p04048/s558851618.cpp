#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)

int para(int a,int b){
  if(a%b==0)return 2*a-b;
	else return a/b*2*b+para(b,a%b);
}



signed main(){
	int n,x;cin>>n>>x;
	int ret=0;
	int y=n-x;
	if(y<x)swap(x,y);
	ret=n+para(y,x);
	cout<<ret<<endl;
}
