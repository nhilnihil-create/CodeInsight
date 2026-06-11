#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n=0,s=0,e=0,w=0,l=0;
	string a;
	cin>>a;
	l=a.length();
	for(int i=0;i<l;i++){
		if(a.substr(i,1)=="E")e=1;
		if(a.substr(i,1)=="W")w=1;
		if(a.substr(i,1)=="N")n=1;
		if(a.substr(i,1)=="S")s=1;
	}
	if(n==0 && s==0 && e==0 && w==0){
		cout<<"Yes"<<endl;
	}else if(n==1 && s==1 && e==1 && w==1){
		cout<<"Yes"<<endl;
	}else if(n==1 && s==1 && e==0 && w==0){
		cout<<"Yes"<<endl;
	}else if(n==0 && s==0 && e==1 && w==1){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
