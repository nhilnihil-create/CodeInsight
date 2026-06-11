#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 1

#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <random>

const long long INF = 10000000000000000;

using namespace std;

int main(){

	int H,W;
	cin>>H>>W;
	string S[30][30];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>S[i][j];
		}
	}
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(S[i][j]=="snuke"){
				printf("%c%d\n",65+j,i+1);
				return 0;
			}
		}
	}
	return 0;	
}
