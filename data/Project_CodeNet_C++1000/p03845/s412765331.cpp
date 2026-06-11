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
#define MAX_N 100000
#define INF 100000000000
ll dp[MAX_N];

int main()
{
	int n;
	cin>>n;
	int sum = 0;
	int *t = new int[n];
	rep(i,n){
		cin>>t[i];
		sum += t[i];
	}
	int m;
	cin>>m;
	pair<int,int> *drink = new pair<int,int>[m];
	rep(i,m){
		int no,t2;
		cin>>no>>t2;
		no--;
		drink[i].first = no;
		drink[i].second = t2;
	}
	rep(i,m){
		cout<< sum - t[drink[i].first] + drink[i].second<<endl;
	}
	return 0;
}

