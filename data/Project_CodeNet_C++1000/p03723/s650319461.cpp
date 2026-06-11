#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, n=0, _a, _b, _c;
	cin>>a>>b>>c;
	while(a%2==0 && b%2==0 && c%2==0){
		if(a==b && b==c){
			n=-1;
			break;
		}
		_a = (b+c)/2;
		_b = (a+c)/2;
		_c = (a+b)/2;
		a = _a;
		b = _b;
		c = _c;
		n++;
	}
	cout << n << endl;
}