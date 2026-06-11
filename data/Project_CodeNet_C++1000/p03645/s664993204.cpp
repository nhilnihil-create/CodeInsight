#include <iostream>
#include <bitset>
using namespace std;

int main(){
	int n,m,a,b;
	cin>>n>>m;
	bitset <200000> f1,tn;
	while(m--){
		cin>>a>>b;
		if(a==1)
			f1.set(b);
		else if(b==n)
			tn.set(a);
	}
	if((f1&tn).none())
		cout<<"IMPOSSIBLE"<<endl;
	else
		cout<<"POSSIBLE"<<endl;
}
