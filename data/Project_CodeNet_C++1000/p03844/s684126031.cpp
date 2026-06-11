#include <iostream>
#include <string>
using namespace std;

int a,b;
string input;

int main(){
	cin>>a>>input>>b;
	if(input[0]=='-'){
		cout<<a-b<<endl;
	}else{
		cout<<a+b<<endl;
	}
}

 
