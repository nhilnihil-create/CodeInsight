#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string a,b,c; cin>>a>>b>>c;
	char n=a[0]; a.erase(0,1);
	while(1){
		if(n=='a'){
			if(a.size()==0){cout<<'A'<<endl; return 0;}
			n=a[0];
			a.erase(0,1);
		}else if(n=='b'){
			if(b.size()==0){cout<<'B'<<endl; return 0;}
			n=b[0];
			b.erase(0,1);
		}else{
			if(c.size()==0){cout<<'C'<<endl; return 0;}
			n=c[0];
			c.erase(0,1);
		}
	}
}