#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100001],ss[100001];
int main(){
	scanf("%s",s);
	memcpy(ss,s,sizeof(s));
	int n=strlen(s);
	reverse(s,s+n);
	for(int i=0; i<n; ++i)
		switch(s[i]){
			case 'd':
				s[i]='b';
				break;
			case 'b':
				s[i]='d';
				break;
			case 'p':
				s[i]='q';
				break;
			case 'q':
				s[i]='p';
				break;
		}
	puts(strcmp(ss,s)?"No":"Yes");
	return 0;
}