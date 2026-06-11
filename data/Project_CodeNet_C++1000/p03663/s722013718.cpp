#include <bits/stdc++.h>
using namespace std;
int main(){
	cout << "? 10000000000" << endl; 
	char c; cin >> c; 
	if(c == 'Y'){
		long long now = 9; 
		for(int i = 0; i < 114514; i++){
			cout << "? " << now << endl; 
			char d; cin >> d; 
			if(d == 'Y'){
				cout << "! " << (now + 1) / 10 << endl; 
				return 0; 
			}
			now *= 10; now += 9; 
		}
	}else{
		long long now = 10; 
		for(int i = 0; i < 114514; i++){
			cout << "? " << now << endl; 
			char d; cin >> d; 
			if(d == 'N') break; 
			now *= 10; 
		}
		long long ng = now / 10; 
		long long ok = now - 1; 
		while(ok - ng > 1){
			long long mid = (ng + ok) / 2; 
			cout << "? " << mid * 10 << endl; 
			char d; cin >> d; 
			if(d == 'Y') ok = mid; 
			else ng = mid; 
		}
		cout << "! " << ok << endl; return 0;
	}
}