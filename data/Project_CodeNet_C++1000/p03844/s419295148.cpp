#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;




int main(){

	int A,B;
	char buf[2];

	scanf("%d %s %d",&A,buf,&B);

	if(buf[0] == '+'){

		printf("%d\n",A+B);

	}else{

		printf("%d\n",A-B);
	}

	return 0;
}
