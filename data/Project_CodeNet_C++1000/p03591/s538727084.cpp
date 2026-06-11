#include<cstdio>
using namespace std;
const int maxn=10+2;
char str[maxn];
int main(){
	scanf("%s",str+1);
	if (str[1]=='Y'&&str[2]=='A'&&str[3]=='K'&&str[4]=='I') printf("Yes");
	else printf("No");
	return 0;
}