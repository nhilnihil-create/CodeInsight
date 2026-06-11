#include <iostream>
#include <string>
using namespace std;

int panjang,pnjg;
string s;
string t;
string u;

int main(){
	cin>>s;
	panjang=s.length();
	for(int i=panjang-1;i>=0;i--){
		s.erase(i,1);
		pnjg=s.length();
		if(pnjg%2==0){
			t=s.substr(0,pnjg/2);
			u=s.substr(pnjg/2,pnjg-1);
			if(t==u){
				i=-1;
				cout<<pnjg<<endl;
			}
		}
	}
}
		