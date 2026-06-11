#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


char buf[105];

int main(){

	scanf("%s",buf);

	int len;

	for(len = 0; buf[len] != '\0'; len++);

	printf("%c%d%c\n",buf[0],len-2,buf[len-1]);

	return 0;
}
