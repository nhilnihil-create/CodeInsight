#include<iostream>
#include<string>
using namespace std;
 
int main(){
	long long a,b;
	string s,s2;
 
	cin >> s;

	while(s.size() > 1){
		s = s.erase(s.size() - 1);
		
		if(s.substr(0, s.size() / 2) == s.substr(s.size() / 2)){
			break;			
		}
	}
 
 
	cout << s.size() << endl;
}