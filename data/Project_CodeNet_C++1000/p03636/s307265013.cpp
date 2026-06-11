#include<cstring>
#include<iostream>
using namespace std;
char c[105];
int main(){
	cin>>c;
	int len=strlen(c);
	cout<<c[0]<<len-2<<c[len-1];
	return 0;
}