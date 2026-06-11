#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 4*atan(1.0)
#define mp make_pair
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef long double ld;
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int ddx[8]={0,0,-1,1,1,1,-1,-1};
int ddy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=100050;
//int arr[SIZE]={};
int main(){
	ll X,Y;
	cin>>X>>Y;
	if(llabs(X-Y)<=1)
		cout<<"Brown"<<endl;
	else
		cout<<"Alice"<<endl;
	return 0;
}