#include <iostream>
#include <string>
using namespace std;

int h, w;
string input [102];

int main (){
	cin>>h>>w;
	for (int i=1; i<=h; i++)
		cin>>input [i];
	for (int i=1; i<=w+2; i++){
		cout<<"#";
	}
	cout<<endl;
	for (int i=1; i<=h; i++){
		cout<<"#"<<input [i]<<"#"<<endl;
	}
		for (int i=1; i<=w+2; i++){
		cout<<"#";
	}
}