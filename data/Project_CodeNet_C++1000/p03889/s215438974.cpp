#include<iostream>
#include<cstring>
using namespace std;
char s[100000];

int main(){
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++){
		char trans;
		switch(s[len-i-1]){
			case 'b':
				trans='d';
				break;
			case 'd':
				trans='b';
				break;
			case 'p':
				trans='q';
				break;
			case 'q':
				trans='p';
				break;
		}
		if(s[i]!=trans){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
} 