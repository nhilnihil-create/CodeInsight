#include <iostream>
#include <string>
using namespace std;

char ch[200000];

int main() {
	std::ios::sync_with_stdio(false);
	string str;
	cin>>str;
	int i=0;
	int t=-1;
	int len=str.length();
	int countt=0;
	while(i<len){
		if(str[i]=='S'){
			++t;
			ch[t]='S';
		}
		if(str[i]=='T'){
			if(t==-1){
				++countt;
			}
			if(t>=0){
				--t;
			}
		}
		++i;
	}
	printf("%i\n",t+1+countt);
	return 0;
}