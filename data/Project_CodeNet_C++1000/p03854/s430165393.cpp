#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

string words[4];
char S[SIZE];

int main(){


	int len[4];

	words[0] = "dream";
	words[1] = "dreamer";
	words[2] = "erase";
	words[3] = "eraser";

	for(int i = 0; i < 4; i++){

		len[i] = words[i].length();
	}


	scanf("%s",S);

	int length;
	for(length = 0; S[length] != '\0'; length++);

	int loc = length-1;

	while(loc >= 0){

		int tmp = -1;
		for(int i = 0; i < 4; i++){
			if(loc+1 < len[i])continue;

			bool FLG  = true;
			for(int k = 0; k < len[i]; k++){
				if(S[loc-k] != words[i][len[i]-1-k]){
					FLG = false;
					break;
				}
			}
			if(FLG){
				tmp = i;
				break;
			}
		}

		if(tmp == -1)break;

		loc -= len[tmp];
	}

	if(loc == -1){

		printf("YES\n");

	}else{

		printf("NO\n");
	}

	return 0;
}
