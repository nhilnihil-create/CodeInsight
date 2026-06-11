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

	int ans = 0;
	for(int i = 1; S[i] != '\0'; i++){
		if(S[i] != S[i-1]){

			ans++;
		}
	}

	printf("%d\n",ans);

	return 0;
}
