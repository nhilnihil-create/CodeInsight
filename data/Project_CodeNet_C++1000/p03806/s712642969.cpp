//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <deque>
#include <cmath>
#include <bitset>
#include <complex>
#include <time.h>
#include <stdio.h>

using namespace std;
typedef long long ll;
typedef pair<double, double> P;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mpa make_pair
#define all(a) a.begin(), a.end()

template<typename T>
void vdeb(vector<T> &da) {
	int size = da.size();
	for (int i = 0;i < size;i++) {
		if (i == size - 1) {
			cout << da[i] << endl;
		}
		else {
			cout << da[i] << ' ';
		}
	}
}
template<typename T>
void vvdeb(vector<T> &da) {
	int size = da.size();
	for (int i = 0;i < size;i++) {
		vdeb(da[i]);
	}
}

struct hoge{
	int a, b, c;
};

int n,a,b;
int dp[410][410];
hoge da[40];

void mint(int &x, int y){
	if(x > y) x = y;
}

int main(){
	cin >> n >> a >> b;
	rip(i,n,0) cin >> da[i].a >> da[i].b >> da[i].c;
	rip(i,410,0){
		rip(j,410,0){
			dp[i][j] = INT_MAX/2;
		}
	}
	dp[0][0] = 0;
	rip(i,n,0){
		for(int j = 400;j>-1;j--){
			for(int k = 400;k>-1;k--){
				mint(dp[j+da[i].a][k+da[i].b], dp[j][k] + da[i].c);
			}
		}
	}
	int ans = INT_MAX/2;
	int x = a,y = b;
	while(x<410 && y < 410){
		mint(ans, dp[x][y]);
		x += a;y += b;
	}
	if(ans == INT_MAX/2){
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}
	
}