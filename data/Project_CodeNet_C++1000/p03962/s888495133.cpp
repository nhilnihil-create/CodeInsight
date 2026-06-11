#include <iostream>
using namespace std;
int main(void){
	int a,b,c,count=1;
		cin >> a;
		cin >>b;
		if(a!=b)count++;
		cin >> c;
		if(c!=a && c!=b)count++;
		cout << count << endl;
	}

