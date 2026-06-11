#include <iostream>
#include <vector>
using namespace std ;

int main(){
	int n,m ;
	cin >> n >> m ;
	vector<bool> ok(n,false) ;
	for(int i=0;i<m;i++){
		int a,b ;
		cin >> a >> b ;
		a-- ; b-- ;
		ok.at(a) = !ok.at(a) ;
		ok.at(b) = !ok.at(b) ;
	}
	bool ans = false ;
	for(int i=0;i<n;i++) if(ok.at(i)) ans = true ;
	cout << (ans?"NO":"YES") << endl ;
}
