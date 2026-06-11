// luogu-judger-enable-o2
#include<iostream>
using namespace std;
int main(){
	string x;
	cin>>x;
	int len=x.length();
	if(x[0]==x[len-1])
		if(len&1) cout<<"Second";
		else cout<<"First";
	else if(len&1) cout<<"First";
			else cout<<"Second";
}