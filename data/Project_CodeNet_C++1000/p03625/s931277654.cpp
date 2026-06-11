#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;


int main(){
	int n ; cin >> n ;
	vector<long long> a(n) ;
	for(auto &i:a) cin >> i ;
	sort(a.begin(),a.end()) ;
	long long l,m ;
	l = m = 0 ;
	for(int i=n-1;i>0;i--){
		if(a.at(i)==a.at(i-1)){
			if(l==0) l = a.at(i) ;
			else{
				m = a.at(i) ;
				break ;
			}
			i-- ;
		}
	}
	cout << l*m << endl ;
}
