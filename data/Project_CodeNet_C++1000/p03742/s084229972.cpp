#include<iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <vector>
#include <cstdio>
#include <cstring>
#include<cmath>
#include <bitset>
typedef long long ll;
const int maxn = 1e5+7;
int c[maxn],v[maxn];
using namespace std;
int main() {
	// freopen("IN4.txt", "r", stdin);
	ll x,y;
	cin>>x>>y;
	if(abs(y-x)<=1)cout<<"Brown"<<endl;
	else cout<<"Alice"<<endl;
}
