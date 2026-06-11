#include <bits/stdc++.h>
using namespace std;

char s[100010],a[5]="bpqd";
bool m[128][128];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	if(n%2!=0){
		printf("No\n");
		return 0;
	}
	for(int i=0;i<4;i++)
		m[a[i]][a[3-i]]=true;
	for(int i=0;i<n/2;i++)
		if(!m[s[i]][s[n-i-1]]){
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	return 0;
}