#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	char a,b; cin>>a>>b;
	if(a=='H'){
		if(b=='H') cout<<'H'<<endl;
		else cout<<"D"<<endl;
	}else if(a=='D'){
		if(b=='H') cout<<'D'<<endl;
		else cout<<"H"<<endl;
	}		
}