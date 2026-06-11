#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string a,b; cin>>a>>b;
	int as=a.size();
	int bs=b.size();
	if(a==b) {cout<<"EQUAL"<<endl; return 0;}
	if(as>bs) cout<<"GREATER"<<endl;
	else if(as<bs) cout<<"LESS"<<endl;
	else{
		rep(i,as){
			if(a[i]>b[i]) {cout<<"GREATER"<<endl; return 0;}
			else if(a[i]<b[i]) {cout<<"LESS"<<endl; return 0;}
		}
	}
}