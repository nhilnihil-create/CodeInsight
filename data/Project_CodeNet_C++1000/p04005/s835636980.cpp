#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	long long a, b, c, jShu = 0x3f3f3f3f3f3f3f3f;
	cin >> a >> b >> c;
	if(a%2 && b*c < jShu) jShu = b*c;
	if(!(a%2)) jShu = 0;
	
	if(b%2 && a*c < jShu) jShu = a*c;
	if(!(b%2)) jShu = 0;
	
	if(c%2 && a*b < jShu) jShu = a*b;
	if(!(c%2)) jShu = 0;
	
	cout << jShu << endl;
}