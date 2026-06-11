#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	int W,a,b;

	scanf("%d %d %d",&W,&a,&b);


	if(b+W <= a){

		printf("%d\n",a-(b+W));

	}else if(a+W <= b){

		printf("%d\n",b-(a+W));

	}else{

		printf("0\n");
	}

	return 0;
}
