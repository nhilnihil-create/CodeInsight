#include <bits/stdc++.h>
using namespace std;
int n , k , x[200000] , maxi , f;
int fpb(int a , int b){
	if(a == 0)return b;
	return fpb(b % a , a);
}
int main(){
	cin >> n >> k;
	for(int i = 1 ; i <=n ; i++){
		cin >> x[i];
		if(i == 1)f = x[i];
		maxi = max(x[i] , maxi);
		f = fpb(f , x[i]);
	}
	if(k <= maxi && k % f == 0)cout << "POSSIBLE" << endl;
	else cout <<  "IMPOSSIBLE" << endl;
}