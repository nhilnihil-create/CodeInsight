#include<iostream>
using namespace std;
#include<algorithm>
#include<cstring>
#include<string>
#include<stdio.h>
#include<map>
#include<vector>
#include<cmath>
#include<iomanip>
#include<queue>
#include<stack>
#include<set>
#define maxn 1000005
#define INF 1e9
#define ll long long
char ch[maxn];
stack<int> sta;
int main()
{
	cin >> ch;
	int ans = 0,len=strlen(ch);
	for (int i = 0; i < len; i++) {
		if (ch[i] == 'S')
			sta.push(i);
		else {
			if (!sta.empty()) {
				ans += 2;
				sta.pop();
			}
			else continue;
		}
	}
	cout << len - ans << endl;
	return 0;
}