#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	int g = 0;
	int p = 0;
	for(auto c: s){
		if(c == 'g') g++;
		else p++;
	}
	if (g - p <= 1) {
		cout << 0;
	} else {
		cout << (g - p) / 2;
	}
	return 0;
}