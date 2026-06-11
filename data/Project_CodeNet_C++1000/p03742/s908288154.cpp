#include <iostream>
using namespace std;
long long x, y;
int main() {
	cin>>x>>y;
	cout<<(x-y<-1 || x-y>1 ? "Alice" : "Brown");
	return 0;
}