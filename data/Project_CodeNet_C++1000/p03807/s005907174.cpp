#include <bits/stdc++.h>
using namespace std;
int n , x , ganjil;
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> x;
		if(x % 2 != 0)ganjil++;
	}
	if(ganjil % 2 == 0)cout << "YES" << endl;
	else cout << "NO" << endl;
}
