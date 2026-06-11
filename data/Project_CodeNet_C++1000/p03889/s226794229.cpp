#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
using namespace std;
string s;
inline char correspond(char const x){return ((!(x-'b'))?('d'):(((!(x-'d'))?('b'):(((!(x-'p'))?('q'):('p'))))));}
signed main()
{
	getline(cin,s);string s1;
	for(register int i(0);i^s.length();i++){s1+=(correspond(s[i]));}reverse(s1.begin(),s1.end());
	puts(((s==s1)?("Yes"):("No")));
	return 0;
}