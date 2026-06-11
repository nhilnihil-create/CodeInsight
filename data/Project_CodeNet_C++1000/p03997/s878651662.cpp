#include<iostream>
using namespace std;

int main(){
	int a,b,h;
	cin >> a;
	cin >> b;
	cin >> h;
	
	if(1>a || a>100 ||1>b || b>100 || 1>h || h>100)exit(1);
	if(h%2 != 0)exit(1);
	
	cout << (a+b)*h/2;

return 0;
}
