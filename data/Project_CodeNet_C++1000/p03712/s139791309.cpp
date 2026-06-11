#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b;
  	string S;
	cin >> a >> b;
  	for (int i = 0; i < b+2; i++){
    	if (i == b+1){
        	cout << "#" << endl;
        }
      	else{
        	cout << "#";
        }
    }
  	for (int i = 0; i < a; i++){
    	cin >> S;
    	cout << '#' + S + '#' << endl;
    }
  	for (int i = 0; i < b+2; i++){
    	if (i == b+1){
        	cout << "#" << endl;
        }
      	else{
        	cout << "#";
        }
    }
}
