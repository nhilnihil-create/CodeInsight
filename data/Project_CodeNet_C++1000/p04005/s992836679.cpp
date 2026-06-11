#include <iostream>
using namespace std;

int main() {
	long long int a,b,c;
	cin>>a>>b>>c;
	if(a*b*c%2==0) cout<<0<<endl;
	else cout<<min(a*b,min(b*c,a*c))<<endl;
	return 0;
} 