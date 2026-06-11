#include <iostream>
#include <string>
using namespace std;

int panjang,freq[26];
string s;
bool valid;

int main(){
	cin>>s;
	panjang=s.length();
	for(int i=0;i<panjang;i++){
		freq[s[i]-'a']++;
	}
	valid=true;
	for(int i=0;i<26;i++){
		if(freq[i]>1){
			valid=false;
		}
	}
	if(valid==true){
		cout<<"yes"<<endl;
	}else{
		cout<<"no"<<endl;
	}
}
		
	