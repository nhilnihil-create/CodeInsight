#include <iostream>
using namespace std;

int main() {
	int x,y,a,b;
	cin>>x>>y>>a>>b;
	if(x*y==a*b){
		cout<<x*y;
		return 0;
	}
	if(x*y>a*b){
		cout<<x*y;
		return 0;
	}
	cout<<a*b;
}