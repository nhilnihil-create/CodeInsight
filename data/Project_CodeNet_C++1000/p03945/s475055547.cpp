#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

char s[N];
int n , ans;

int main(){
	scanf("%s" , s + 1) , n = strlen(s + 1);
	for(int i = 2; i <= n; i++)
		if(s[i] != s[i - 1]) ans++;
	printf("%d" , ans);
	return 0;
}