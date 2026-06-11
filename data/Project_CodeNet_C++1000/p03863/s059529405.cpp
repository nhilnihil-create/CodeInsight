#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

char S[SIZE];

int main(){

	scanf("%s",S);

	int len;
	for(len = 0; S[len] != '\0'; len++);

	if(S[0] == S[len-1]){

		if(len%2 == 1){

			printf("Second\n");

		}else{

			printf("First\n");
		}

	}else{

		if(len%2 == 1){

			printf("First\n");

		}else{

			printf("Second\n");
		}
	}

	return 0;
}
