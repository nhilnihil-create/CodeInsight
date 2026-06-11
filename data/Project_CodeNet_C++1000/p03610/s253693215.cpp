#include <iostream>
#include <string>
using namespace std;

int panjang;
string s;
string t;

int main(){
	cin>>s;
	panjang=s.length();
	if(panjang%2==0){
		panjang-=1;
	}
	for(int i=0;i<=panjang;i+=2){
		t+=s[i];
	}
	cout<<t<<endl;
}