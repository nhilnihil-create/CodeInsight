#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	string s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	char c1 = s1[0] - 0x20, c2 = s2[0] - 0x20,c3 = s3[0] - 0x20;
	cout << c1 << c2 << c3 << endl;
	return 0;
}