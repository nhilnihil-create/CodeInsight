#include <iostream>
using namespace std;

int main(){
	string S;cin >> S;
  	string R = S.substr(0,4);
  	string T = S.substr(4,8);
  	cout << R << " " << T << endl;
}