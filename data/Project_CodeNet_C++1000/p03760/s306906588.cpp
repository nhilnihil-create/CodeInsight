#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;





int main(){

	char O[55],E[55];
	scanf("%s %s",O,E);

	for(int i = 0; O[i] != '\0'; i++){

		printf("%c",O[i]);
		if(E[i] != '\0'){
			printf("%c",E[i]);
		}
	}
	printf("\n");

	return 0;
}
