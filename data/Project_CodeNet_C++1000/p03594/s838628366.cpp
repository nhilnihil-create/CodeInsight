#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

const char mod[] = "YGBR";
int N , M , K;
char qbxf[2007][2007] , ans[1007][1007];

int main(){
	cin >> N >> M >> K;
	for(int i = -1000 ; i <= 1000 ; ++i)
		for(int j = -1000 ; j <= 1000 ; ++j)
			qbxf[i + 1000][j + 1000] = mod[((i + 1000) / K & 1) * 2 + ((j + 1000) / K & 1)];
	for(int i = -1000 ; i <= 1000 ; ++i)
		for(int j = -1000 ; j <= 1000 ; ++j)
			if((i + j) >= 0 && (i - j) >= 0 && !((i + j) & 1))
				ans[(i + j) / 2][(i - j) / 2] = qbxf[i + 1000][j + 1000];
	for(int i = 1 ; i <= N ; ++i){
		for(int j = 1 ; j <= M ; ++j)
			putchar(ans[i][j]);
		putchar('\n');
	}
	return 0;
}
