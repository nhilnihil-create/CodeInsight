#include<bits/stdc++.h>
using namespace std;
char s[100050];
int l,i,j;
int main()
{
	gets(s);
	l=strlen(s);
	if(l%2){
		puts("No");
		return 0;
	}
	for(i=0,j=l-1;i<j;i++,j--){
		if(s[i]=='p'&&s[j]!='q'){
			puts("No");
			return 0;
		}
		else{
			if(s[i]=='q'&&s[j]!='p'){
				puts("No");
				return 0;
			}
			else{
				if(s[i]=='b'&&s[j]!='d'){
					puts("No");
					return 0;
				}
				else{
					if(s[i]=='d'&&s[j]!='b'){
						puts("No"); 
						return 0;
					}
				}
			}
		}
	}
	puts("Yes");
	return 0;
}