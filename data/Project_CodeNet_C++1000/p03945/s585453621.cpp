#include <iostream>
using namespace std;

int main(void){
	string s;
	cin >> s;
	char c = s[0];
	int sum = 0;
	for(char i : s){
		if(i != c){
			sum++;
			c = i;
		}
	}
	cout << sum << endl;
}