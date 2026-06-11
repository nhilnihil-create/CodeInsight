#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;

int matrix[50][50];

void init(){
	for(int i = 0; i < 50; i ++){
		for(int j = 0; j < 50; j++){
			matrix[i][j] = 0;
		}
	}
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 0; i < m; i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		matrix[a][b]++;
		matrix[b][a]++;
	}
	for(int i = 0; i < n; i++){
		int ans = 0;
		for(int j = 0; j < n; j++){
			ans += matrix[i][j];
		}
		cout<<ans<<endl;
	}
	return 0;
}

