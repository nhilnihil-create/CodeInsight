#include <iostream>
#include<string>
#include<cmath>
#include<vector>
using std::cin;
using std::cout;
using std::vector;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(b-a==c-b)
		cout<<"YES";
	else
		cout<<"NO";
}