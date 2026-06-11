#include <iostream>
#include <string>
using namespace std ;

string yorn(bool a){if(a) return "Yes" ; return "No" ;}

int main(){
	int n ; cin >> n ;
	int two = 0 ;
	int four = 0 ;
	for(int i=0;i<n;i++){
		int a ; cin >> a ;
		if(a%2==0) two++ ;
		if(a%4==0) four++ ;
	}
	two -= four ;
	cout << yorn(n/2<=four||2*four+two>=n) << endl ;
}
