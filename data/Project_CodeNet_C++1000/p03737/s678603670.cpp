#include <iostream>
#include <string>
using namespace std;

string satu;
string dua;
string tiga;
int main(){
	cin>>satu>>dua>>tiga;
	satu[0]-=32;
	dua[0]-=32;
	tiga[0]-=32;
	cout<<satu[0]<<dua[0]<<tiga[0]<<endl;
}