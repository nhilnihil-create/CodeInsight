#include <iostream>
#include <cstring>
using namespace std;
string s,t;
int main(){
	cin>>s;
	t="";
	for(int i=s.length()-1;i>=0;i--)t+=s[i];
	for(int i=0;i<t.length();i++){
		switch(t[i]){
			case 'b':t[i]='d';break;
			case 'd':t[i]='b';break;
			case 'p':t[i]='q';break;
			case 'q':t[i]='p';break;
		}
	}
	if(s==t)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
