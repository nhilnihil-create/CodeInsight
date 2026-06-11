#include <iostream>

using namespace std;
int main(void){
	string s;
	cin >> s;
	int sum=0;
	for(char c : s){
		if(c=='p')sum++;
	}
	cout << s.size()/2-sum << endl;
}