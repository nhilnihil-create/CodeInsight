#pragma  warning (disable:4996) 
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<utility>
#include<iomanip>
#include<set>
#include <numeric>
#include<map>
using namespace std;
typedef long long ll;
const int dx[] = { -1,1,0,0,-1,-1,1,1 };
const int dy[] = { 0,0,-1,1,-1,1,-1,1 };

int main()
{
	int  x, y;
	scanf("%d%d", &x, &y);
	if (llabs(x - y) >= 2)
		printf("Alice\n");
	else
		printf("Brown\n");
}