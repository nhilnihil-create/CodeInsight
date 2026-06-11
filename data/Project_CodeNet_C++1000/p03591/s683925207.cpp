#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define INF 1 << 30
#define MAX 1000000000
#define SIZE 1000000000

int main() {
	char s[11];
	scanf("%s", s);
	puts(s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I' ? "Yes" : "No");
	return 0;
}