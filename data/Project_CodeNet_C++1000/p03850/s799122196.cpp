#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<string>
#include<stack>
#include<algorithm>
#include<memory.h>
using namespace std;
typedef long long ll;
#define se second
#define fi first
#define pb push_back
const int N = 1e6 + 5, M = 1e9 + 7;
int n, a[N];
char op[N];
ll sm[N];
int main() {
	//	freopen("in.txt", "r", stdin);
		scanf("%d", &n);
		op[0] = '+';
		scanf("%d", &a[0]);
		sm[0] = a[0];
		for (int i = 1;i < n;i++)scanf(" %c%d", &op[i], &a[i]),sm[i]+=sm[i-1]+a[i];
		ll best = 0,pos=0,all=0;
		for (int i = n - 1;i >= 0;i--) {
			if (op[i] == '+')pos += a[i];
			else {
				best = max(best - a[i] + pos, -a[i] - pos + all);
				all += pos + a[i];
				pos = 0;
			}
		}
		best += pos;
		cout << best << endl;
}
