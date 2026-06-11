#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

char buf[SIZE];

int main(){

	scanf("%s",buf);

	int num_g = 0,num_p = 0;
	int win = 0,lose = 0;

	for(int i = 0; buf[i] != '\0'; i++){
		if(buf[i] == 'g'){

			if(num_p+1 <= num_g){
				num_p++;
				win++;
			}else{
				num_g++;
			}

		}else{	//buf[i] == 'p'


			if(num_p+1 <= num_g){
				num_p++;
			}else{
				num_g++;
				lose++;
			}
		}
	}

	printf("%d\n",win-lose);

	return 0;
}
