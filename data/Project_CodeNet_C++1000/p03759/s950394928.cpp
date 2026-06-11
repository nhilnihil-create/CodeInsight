#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int s[11];
int main(){
	scanf("%d%d%d",&s[1],&s[2],&s[3]);
	sort(s+1,s+4);
	if(s[3]-s[2]==s[2]-s[1]) printf("YES");
	else printf("NO");
	return 0;
}
