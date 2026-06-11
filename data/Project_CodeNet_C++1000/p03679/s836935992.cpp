#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int x,a,b;

	scanf("%d %d %d",&x,&a,&b);

	if(b-a <= 0){

		printf("delicious\n");

	}else if(b-a <= x){

		printf("safe\n");

	}else{

		printf("dangerous\n");
	}

	return 0;
}
