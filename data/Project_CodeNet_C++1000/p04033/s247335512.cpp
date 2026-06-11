#include <bits/stdc++.h>
using namespace std;
int a , b;
int main(){
	cin >> a >> b;
	if(a > 0 && b > 0){
		cout << "Positive" << endl;
	}
	else if(a < 0 && b > 0){
		cout << "Zero" << endl;
	}
	else if(a == 0 || b == 0){
		cout << "Zero" << endl;
	}
	else{
		if((a - b + 1) % 2 == 0){
			cout << "Positive" << endl;
		}
		else {
			cout << "Negative" << endl;
		}
	}
}