#include <iostream>
#include <string>
using namespace std;

int pnjg, pnjgedit;
string input, a, b;

int main (){
	cin>>input;
	pnjg=input.length();
	for (int i=pnjg-1; i>=0; i--) {
		input.erase(i, 1);
		pnjgedit=input.length();
		if (pnjgedit%2==0){
			a=input.substr(0, pnjgedit/2);
			b=input.substr(pnjgedit/2, pnjgedit-1);
			if (a==b){
				i=-1;
				cout<<pnjgedit<<endl;
			}
		}
	}
}
	