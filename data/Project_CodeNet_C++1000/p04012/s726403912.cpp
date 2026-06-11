#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#  define LOG(x) (cerr <<">>>>>>"<< #x << " = " << (x) << endl)
#else
#  define LOG(x) ((void)0)
#endif

int c[256];
int main()
{
	string s;
	cin>>s;
	for(char i:s)c[i]++;
	for(char i:s)if(c[i]&1)return 0&puts("No");
	puts("Yes");
	
}

