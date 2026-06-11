#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int a,b; cin>>a>>b;
	if(a>0&&b>0) cout<<"Positive"<<endl;
	else if(a<0&&b>0) cout<<"Zero"<<endl;
	else {
		int r=-a-b;
		if(r%2==1) cout<<"Positive"<<endl;
		else cout<<"Negative"<<endl;
	}
}