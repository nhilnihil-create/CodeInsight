#include<iostream>
#include<string>
using namespace std ;

int main(){
	string s ; cin >> s ;
	for(int i=1;i<s.size();i++){
		if(i==1){
			if(s.at(0)==s.at(1)){
				cout << "1 2" << endl ;
				return 0 ;
			}
		}else{
			if(s.at(i)==s.at(i-1)){
				cout << i << " " << i+1 << endl ;
				return 0 ;
			}
			if(s.at(i)==s.at(i-2)){
				cout << i-1 << " " << i+1 << endl ;
				return 0 ;
			}
		}
	}
	cout << "-1 -1" << endl ;
}