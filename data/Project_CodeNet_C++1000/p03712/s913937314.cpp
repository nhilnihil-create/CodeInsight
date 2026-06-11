#include <iostream>
#include <string>
using namespace std;

int rows, column;
string input [1000];

int main (){
	cin>>rows>>column;
	for (int i=1; i<=rows; i++)
		cin>>input [i];
	for (int i=1; i<=column+2; i++){
		cout<<"#";
	}
	cout<<endl;
	for (int i=1; i<=rows; i++){
		cout<<"#"<<input [i]<<"#"<<endl;
	}
		for (int i=1; i<=column+2; i++){
		cout<<"#";
	}
}