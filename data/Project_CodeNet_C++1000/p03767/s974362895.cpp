#include <bits/stdc++.h>
using namespace std;
long long n , x[500000] , sum ;
int main(){
	cin >> n;
	for(int i = 1 ; i <= 3*n ; i++){
		cin >> x[i];
	}
	sort(x + 1 , x + (3*n) + 1);
	for(int i = (3*n) - 1 ; i >= n ; i -= 2){
		sum += x[i];
	}
	cout << sum << endl;
}