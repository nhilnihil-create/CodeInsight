/******* all required header files *******/
#include<iostream>
#include<algorithm>
#include<cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;

/*****All definitions*******/
#define w(t) int t; cin>>t; while(t--)
#define vi vector<int>
#define vs vector<string>
#define mp make_pair
#define ll long long int
/***************************/

int main()
{
/*#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif*/

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;
	if(a==1) a+=13;
	if(b==1) b+=13;
	if(a>b)
    cout << "Alice" << endl;
	else if(a<b)
	cout << "Bob" << endl;
	else
	cout << "Draw" << endl;
	return 0;
}
