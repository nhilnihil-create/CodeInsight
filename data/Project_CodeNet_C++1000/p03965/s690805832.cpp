#include<iostream>
#include <string>
using namespace std ;

int main(){
	string s ; cin >> s ;
	int cnt = 0 ;
	for(int i=0;i<s.size();i++){
		if(i%2==0){
			if(s.at(i)=='p') cnt-- ;
		}else{
			if(s.at(i)=='g') cnt++ ;
		}
	}
	cout << cnt << endl ;
}