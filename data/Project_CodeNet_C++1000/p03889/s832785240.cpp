#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s,s1;
	int i;
	cin>>s;
	s1=s;
	reverse(s.begin(),s.end());
	for(i=0;i<s.size();i++){
		if(s[i]=='b'){
			s[i]='d';
		}else if(s[i]=='d'){
			s[i]='b';
		}else if(s[i]=='p'){
			s[i]='q';
		}else{
			s[i]='p';
		}
	}
	if(s==s1){
		cout<<"Yes";
	}else{
		cout<<"No";
	}
	return 0;
}