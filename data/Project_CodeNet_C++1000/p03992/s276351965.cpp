#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string a;
	cin>>a;
	for(register int i=0;i<4;i++) putchar(a[i]);
	putchar(' ');
	for(register int i=4;i<12;i++) putchar(a[i]);
	puts("");
	return 0;
}
