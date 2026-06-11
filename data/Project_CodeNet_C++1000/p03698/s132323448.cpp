#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int table[26];
char buf[30];

int main(){

	for(int i = 0; i < 26; i++){

		table[i] = 0;
	}

	scanf("%s",buf);
	for(int i = 0; buf[i] != '\0'; i++){

		table[buf[i]-'a']++;
		if(table[buf[i]-'a'] == 2){

			printf("no\n");
			return 0;
		}
	}

	printf("yes\n");

	return 0;
}
