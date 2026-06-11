#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;
#define MAX_N 100

char field[MAX_N][MAX_N];

int main()
{
	int h,w;
	cin>>h>>w;
	rep(i,h){
		rep(j,w) cin>>field[i][j];
	}
	rep(i,h){
		rep(j,w) cout<<field[i][j];
		cout<<endl;
		rep(j,w) cout<<field[i][j];
		cout<<endl;
	}

	return 0;
}

