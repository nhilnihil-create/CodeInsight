#include<bits/stdc++.h>
using namespace std;
char modmodmod(char ch) {
	if(ch=='b')return 'd';
	if(ch=='d')return 'b';
	if(ch=='p')return 'q';
	if(ch=='q')return 'p';
}
int main() {
	string str,tmp;
	cin>>str;
	tmp=str;
	reverse(str.begin(),str.end());
	for(int i=0; i<str.size(); i++)
		str[i]=modmodmod(str[i]);
	puts(tmp==str?"Yes":"No");
	return 0;
}