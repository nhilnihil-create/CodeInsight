#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <list>
#include <numeric>
#include <map>
#include <cmath>
#include <string>

#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
typedef long long ll;
using namespace std;
//================================================

int a = 0, b = 0, c, d, n, k = 0;
string s, t;



int main()
{
	cin >> a >> b >> c;
	cout << (a + b + c) - max({ a,b,c }) << endl;
	return 0;
}