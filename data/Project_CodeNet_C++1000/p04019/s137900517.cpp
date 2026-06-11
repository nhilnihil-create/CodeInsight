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
string s;
int main()
{
	cin >> s;
	int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'N')ans1++;
		else if (s[i] == 'S')ans2++;
		else if (s[i] == 'W')ans3++;
		else ans4++;
	}
	if ((ans1 && !ans2) || (ans2 && !ans1) || (ans3 && !ans4) || (ans4 && !ans3))cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}