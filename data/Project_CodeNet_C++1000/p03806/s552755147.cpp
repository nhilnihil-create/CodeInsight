#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;
typedef long long ll;

int main()
{
	const int NMax = 40;
	const int SumMax = NMax * 10;
	
	int N, Ma, Mb;
	int a[NMax+1];
	int b[NMax+1];
	int c[NMax+1];
	cin >> N >> Ma >> Mb;
	for(int i = 1; i < N+1; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	
	static int DP[NMax+1][SumMax+1][SumMax+1];
	for(int i = 0; i < N+1; i++){
		for(int j = 0; j < SumMax+1; j++){
			for(int k = 0; k < SumMax+1; k++){
				DP[i][j][k] =  j == 0 && k == 0 ? 0 : INT_MAX / 2;
			}
		}
	}
	
	for(int i = 1; i < N+1; i++){
		for(int j = 0; j < SumMax+1; j++){
			for(int k = 0; k < SumMax+1; k++){
				if(j-a[i] >= 0 && k-b[i] >= 0){
					DP[i][j][k] = DP[i-1][j-a[i]][k-b[i]] + c[i];
				}
				DP[i][j][k] = min(DP[i][j][k], DP[i-1][j][k]);
			}
		}
	}
	
	int ans = INT_MAX;
	for(int i = 1; Ma * i <= SumMax && Mb * i <= SumMax; i++){
		for(int j = 1; j < N+1; j++){
			ans = min(ans, DP[j][Ma*i][Mb*i]);
		}
	}
	
	if(ans >= INT_MAX / 2){
		cout << "-1" << endl;
	}else{
		cout << ans << endl;
	}
	
	return 0;
}
