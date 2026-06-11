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
typedef long long ll;

struct task{
	int cost;
	int deadLine;
};

bool myComp(task left,task right){
	return (left.deadLine < right.deadLine);
}

int main()
{
	int n;
	cin>>n;
	int ans = 0;
	int ansNum = 1;
	for(int i = 1; i <= n; i++){
		int temp = i;
		int num = 0;
		while( temp % 2 == 0 ){
			num++;
			temp /= 2;
		}
		if( num >= ans){
			ans = num;
			ansNum = i;
		}
	}
	cout<<ansNum<<endl;
	return 0;
}

