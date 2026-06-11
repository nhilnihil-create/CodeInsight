#include<cstdio>
const int N=100002;
char s[N];
int n;
int main(){
	scanf("%s",s+1);
	while(s[n+1])n++;
	printf("%s\n",((s[1]==s[n])+n)%2?"First":"Second");
}