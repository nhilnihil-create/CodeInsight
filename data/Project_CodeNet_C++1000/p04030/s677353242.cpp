#include <iostream>
#include <string>

using namespace std;
int main(void){
	string s;
	cin >> s;
	string res;
	for(char c : s){
		if(c!='B')res.push_back(c);
		else if(res.size()>0)res.pop_back();
	}
	cout << res << endl;
}