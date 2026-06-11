#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



char buf[20];

int main(){

	scanf("%s",buf);

	for(int i = 0; buf[i] != '\0'; i++){
		if(buf[i] == ','){

			buf[i] = ' ';
		}
	}

	printf("%s\n",buf);

	return 0;
}
