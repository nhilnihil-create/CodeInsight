#include <iostream>

#include<string>
using namespace std;

int main() {
	string s;
	cin>>s;
	if(s[0]=='Y'){
		if(s[1]=='A'){
			if(s[2]=='K'){
				if(s[3]=='I'){
					cout<<"Yes"<<endl;
					return 0;
				}
			}
		}
	}
	cout<<"No"<<endl;

	return 0;
}
