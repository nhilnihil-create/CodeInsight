#include<iostream>
using namespace std;
int a,b;
char c;
int main(){
	cin >> a;
	cin >> c;
	cin >> b;
	if (c=='+'){
		cout << a+b << "\n";
	}else{
		cout << a-b << "\n";
	}
	return 0;
}