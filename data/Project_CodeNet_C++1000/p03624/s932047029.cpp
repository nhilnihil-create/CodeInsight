#pragma target("avx")
#pragma optimize("O3")
#include<bits/stdc++.h>

bool alp[26];
char c;

int main(){
	while((c=getchar())!='\n') alp[c-'a'] = true;
	for(int i=0; i<26; i++) if(!alp[i]) {
		putchar(i+'a');
		return 0;
	}
	puts("None");
	return 0;
}

