#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int judge(int &n){
	if(n==2){n=1; return n;}
	if(n==4||n==6||n==9||n==11){n=2; return n;}
	else{n=3; return n;}
}

int main(){
	int x,y; cin>>x>>y;
	judge(x);
	judge(y);
	if(x==y) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}