#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



char buf[100005];

int main(){

	scanf("%s",buf);

	int len;
	for(len = 0; buf[len] != '\0'; len++);

	for(int i = 0; i < len-1; i++){
		if(buf[i] == buf[i+1]){

			printf("%d %d\n",i+1,i+2);
			return 0;
		}
		if(i+4 < len && buf[i] == buf[i+2]){

			printf("%d %d\n",i+1,i+3);
			return 0;
		}
	}

	printf("-1 -1\n");

	return 0;
}
