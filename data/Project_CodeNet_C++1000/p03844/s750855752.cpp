#include<iostream>
using namespace std;
int main(){
	int a,b,result;
	char symbol;
	cin>>a;
	cin>>symbol;
	cin>>b;
	result=(symbol=='+')?a+b:result;
	result=(symbol=='-')?a-b:result;
	cout<<result;
	return 0;
}