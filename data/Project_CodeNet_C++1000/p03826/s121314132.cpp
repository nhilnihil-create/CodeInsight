#include <iostream>
using namespace std;

int main() {
	int a;
	int b;
	int c;
	cin>>a;
	cin>>b;
	a*=b;
	cin>>b;
	cin>>c;
	b*=c;
	if(b>a){
		cout<<b<<endl;
	}
	else{
		cout<<a<<endl;
	}
}