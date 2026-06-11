#include <bits/stdc++.h>
using namespace std;

int n, a, b, pass=0, passb=0;
string part;

int main() {
	cin >> n >> a >> b >> part;

	for(char element: part){
		if (element == 'a'){
			if(pass < a+b){
				cout << "Yes" << endl;
				pass++;
			}
			else
				cout << "No" << endl;
		}
		else if (element == 'b'){
			if(pass < a+b && passb < b){
				cout << "Yes" << endl;
				pass++;
				passb++;
			}
			else
				cout << "No" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
}