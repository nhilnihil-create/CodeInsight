#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	cin>>s;
	s.insert(4," ",1);
	for(int i=0;i<s.size();i++){
		cout<<s[i];
	}
	cout<<endl;
	return 0;
}