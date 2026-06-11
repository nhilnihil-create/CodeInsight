#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int len;
string s1;

int main(){
	cin>>s1;
	len=s1.length();
	for(int i=0;i<len;i++)
		if((s1[i]=='b' && s1[len-i-1]!='d') || (s1[i]=='d' && s1[len-i-1]!='b') || (s1[i]=='q' && s1[len-i-1]!='p') || (s1[i]=='p' && s1[len-i-1]!='q')){
			printf("No");
			return 0;
		}
	printf("Yes");
	return 0;
}