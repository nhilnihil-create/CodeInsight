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
	string str;
	cin>>str;
	str.pop_back();
	int n = str.length()/2;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if( str.substr(0,i) == str.substr(i,i)) ans = max(ans,i*2);
	}
	cout<<ans<<endl;
	return 0;
}

