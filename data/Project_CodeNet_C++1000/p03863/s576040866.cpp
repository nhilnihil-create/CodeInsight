#include <iostream>
using namespace std;
int main(void){
	string s;
	cin >> s;
	int flag =1;
	for(int i=0;i<=s.size()-3;i++){
		int j= i+2;
		if(s[i]!=s[j]){
			flag=0;
			break;
		}
	}
	if(flag){
		cout << "Second" << endl;
		return 0;
	}
	if(s[0]!=s[s.size()-1]){
		if(s.size()%2)cout<< "First" <<endl;
		else cout << "Second" << endl;
	}
	else{
		if(s.size()%2)cout<< "Second" <<endl;
		else cout << "First" << endl;
	}
}