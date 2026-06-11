#include <iostream>
#include <string>
using namespace std;
int main(void){
	string s;
	cin >> s;
	string r="";
	for(auto a=s.begin();a!=s.end();a++){
		if(r=="")if(*a=='B')continue;
		if(*a=='B')r.pop_back();
		else if(*a=='0')r+='0';
		else if(*a=='1')r+='1';
	}
	cout << r << endl;
	return 0;
}