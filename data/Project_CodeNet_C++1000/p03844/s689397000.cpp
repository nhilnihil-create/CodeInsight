#include <iostream>
#include <string>
using namespace std;

int a, b;
string op, tambah="+";

int main (){
	cin>>a>>op>>b;
	if (op [0]==tambah [0]){
		cout<<a+b<<endl;
	}else {
		cout<<a-b<<endl;
	}
}