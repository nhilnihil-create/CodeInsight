#include <iostream>
#include <string>
using namespace std;

int pnjg, freq [300], jwb;
string input;

int main (){
	cin>>input;
	pnjg=input.length();
	for (int i=0; i<=pnjg-1; i++){
		freq [input [i]-'a']++;
	}
	for (int i=0; i<26; i++){
		if (freq [i]>1){
			jwb=-1;
		}
	}
	if (jwb==-1){
		cout<<"no"<<endl;
	}else{
		cout<<"yes"<<endl;
	}
}