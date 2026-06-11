#include <iostream>
#include <string>
using namespace std;

int checka,checkz,panjang;
string s;

int main(){
	checka=200001;
    checkz=-1;
	cin>>s;
	panjang=s.length();
	for(int i=0;i<panjang;i++){
		if(s[i]=='A' && i<checka){
			checka=i;
		}else if(s[i]=='Z' && i>checkz){
			checkz=i;
		}
    }
    cout<<checkz-checka+1<<endl;
}