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

	int x = 0,maximum = 0;

	int N;
	scanf("%d",&N);
	scanf("%s",buf);

	for(int i = 0; buf[i] != '\0'; i++){
		if(buf[i] == 'I'){

			x++;
			maximum = max(maximum,x);

		}else{

			x--;
		}
	}

	printf("%d\n",maximum);

	return 0;
}
