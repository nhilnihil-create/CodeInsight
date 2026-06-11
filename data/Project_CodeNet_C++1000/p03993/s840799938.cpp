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
#define SL(a) scanf("%lld", &a)
#define P(a) printf("%d\n", a)
#define PY printf("%s", "Yes");
#define PN printf("%s", "No");
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> IR;

int main(){
	int n;
	S(n);
	vector<int> v(n);
	R(i, n){
		int num;
		S(num);
		v[i] = num - 1;
	}
	int ans = 0;
	vector<bool> che(n);
	R(i, n){
		if(!che[i] && v[v[i]] == i) {
			ans++;
			che[v[i]] = true;
		}
	}
	P(ans);
}