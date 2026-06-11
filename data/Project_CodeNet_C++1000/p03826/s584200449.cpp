#include <iostream>
using namespace std;

int main() {
	int a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1*b1>a2*b2)cout<<a1*b1;
	else cout<<a2*b2;
}