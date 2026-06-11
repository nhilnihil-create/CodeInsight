
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <math.h>
#include <map>
#include <bitset>
#include <queue>
#include <list>
#include <utility>

//#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using p = pair<int, int>;
using Graph = vector<vector<int>>;
#define rep(i,n)  for(int i = 0; i < n ; i++)
int dx[4]{ -1,0,1,0 };
int dy[4]{ 0,1,0,-1 };

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int d = min(a, min(b,c));
	int e = max(a, max(b, c));
	if (e - d == a || e - d == b || e - d == c)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
  return 0;
}
