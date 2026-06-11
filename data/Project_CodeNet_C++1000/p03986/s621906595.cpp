#include<iostream>
#include<string>
#include<sstream>
using namespace std;
const int N=2e5;
char stk[N];
int p=0;
int main(){
	char c;
	stk[0]='T';
	while(cin>>c){
		if(p==0){
			stk[++p]=c;
			continue;
		}
		if(c=='T'&&stk[p]=='S'){
			p--;
			continue;
		}
		stk[++p]=c;
	}
	cout<<p;
} 