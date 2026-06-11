#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100005;
int a,b;
char op;
int main(){
	cin>>a>>op>>b;
	if(op == '+')
		cout<<a+b<<endl;
	else
		cout<<a-b<<endl;
}