#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<string>
#include<iostream>
#define R(i, n) for(int i = 0; i < n; i++)
#define S(a) scanf("%d", &a)
#define S2(a, b) scanf("%d%d", &a, &b)
#define S3(a, b, c) scanf("%d%d%d",  &a, &b, &c)
#define P(a) printf("%d\n", a)
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> IR;

int main(){
	string s;
	cin >> s;
	int ans;
	for(int i = 1; i * 2 < s.length(); i++){
		if(s.substr(0, i) == s.substr(i, i)) ans = i * 2;
	}
	P(ans);
}