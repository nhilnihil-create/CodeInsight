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
	if(n+s==1 || e+w==1){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
	}
	return 0;
}
