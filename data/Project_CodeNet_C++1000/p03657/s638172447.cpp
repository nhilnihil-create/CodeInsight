#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b; cin>>a>>b;
	bool flg=false;
	if(a%3==0) flg=true;
	if(b%3==0) flg=true;
	if((a+b)%3==0) flg=true;
	if(flg) cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
}