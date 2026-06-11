#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int main(){

	int table[13] = {0,1,2,1,3,1,3,1,1,3,1,3,1};

	int x,y;
	scanf("%d %d",&x,&y);

	if(table[x] == table[y]){

		printf("Yes\n");

	}else{

		printf("No\n");
	}

	return 0;
}
