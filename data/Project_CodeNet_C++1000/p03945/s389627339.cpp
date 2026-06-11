#include <iostream>
using namespace std;
int main(void){
	string s;
	int soma=0;
	cin >> s;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]!=s[i+1])soma++;
	}
	cout << soma << endl;
}