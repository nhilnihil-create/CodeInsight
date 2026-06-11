#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	int h,w;
	string str;
	cin >> h >> w;
	for(char i=0;i<h;i++){
		char ch = 'A';
		for(int j=0;j<w;j++){
			cin >> str;
			if(str=="snuke"){
				cout << ch << i+1 << endl;
				break;
			}
			ch = int(ch)+1;
		}
	}
}