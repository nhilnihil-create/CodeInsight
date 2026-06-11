#include <bits/stdc++.h>
using namespace std;
long long n , c , k , t[200000] , pos , ans , isi;
int main(){
	cin >> n >> c >> k;
	for(int i = 1 ; i <= n ; i++){
		cin >> t[i];
	}
	sort(t + 1 , t + n + 1);
	pos = 0;
	isi = c;
	for(int i = 1 ; i <= n ; i++){
		if(isi == 0 || t[i] > pos){
			ans++;
			isi = c - 1;
			pos = t[i] + k;
		}
		else {
			isi--;
		}
	}
	cout << ans << endl;
}