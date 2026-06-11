#include<bits/stdc++.h>
using namespace std;

int main(){
	int A , B , C; cin >> A >> B >> C;
	for(int i = 0 ; i <= 1e6 ; ++i){
		if((A | B | C) & 1){cout << i; return 0;}
		int p = A / 2 , q = B / 2 , r = C / 2;
		A = q + r; B = p + r; C = p + q;
	}
	cout << -1;
	return 0;
}
