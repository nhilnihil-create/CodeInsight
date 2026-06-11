#include <iostream>
#include <string>
using namespace std;

int pnjg, freq [30];
string input, abjad="abcdefghijklmnopqrstuvwxyz";
bool gaada;

int main (){
	gaada=true;
	cin>>input;
	pnjg=input.length();
	for (int i=0; i<pnjg; i++){
		freq [input [i]-'a']++;
	}
	for (int i=0; i<26;i++){
		if (freq [i]==0){
			cout<<abjad[i]<<endl;
			i=27;
			gaada=false;
		}
	}
	if (gaada==true){
		cout<<"None"<<endl;
	}
}