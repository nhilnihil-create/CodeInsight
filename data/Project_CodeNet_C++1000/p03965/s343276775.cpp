#include <iostream>
#include <string>
using namespace std;
int main(void){
	string a;
	int countp=0;
	cin>> a;
	for(char x:a){
		if(x=='p')countp++;
	}
	cout << a.size()/2-countp << endl;
}