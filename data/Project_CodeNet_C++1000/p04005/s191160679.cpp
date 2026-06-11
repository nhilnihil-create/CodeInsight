#include <bits/stdc++.h>
using namespace std;


int main(){
	long long int a,b,c;
	cin >> a >> b >> c;
	if(a%2==0||b%2==0||c%2==0){
		cout << 0 << endl;
	}else{
		if(a>=b&&a>=c){
			cout << b*c << endl;
		}else if(b>=a&&b>=c){
			cout << a*c << endl;
		}else{
			cout << a*b << endl;
		}
	}
}