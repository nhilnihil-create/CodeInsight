#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
char s[N]; int c[30];
int main() {
	scanf("%s",s+1);
	for(int i=1;s[i];i++) c[s[i]-'a']++;
	LL n=strlen(s+1);
	LL tot=n*(n-1)/2;
	for(int i=0;i<26;i++){
		tot=tot-1LL*c[i]*(c[i]-1)/2;
	}
	tot++;
	cout<<tot<<endl;
}