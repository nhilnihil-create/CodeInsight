#include <bits/stdc++.h>
#include <string>
using namespace std;

int a,b,c;
char op;

int main(){
	cin>>a>>op>>b;
	c=(int)op;
	if(c==43){
	    cout<<a+b<<endl;
	}
	else if(c==45){
	    cout<<a-b<<endl;
	}
}
