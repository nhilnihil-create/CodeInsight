#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdint>
#include <vector>
#include <algorithm>
using namespace std;
static const long long MOD = 1000000007LL;
typedef long long ll;

int main()
{
	string a;
	cin>>a;
	for(int i=0;i<4;i++)
		cout<<a[i];
	cout<<" ";
	for(int i=4;i<12;i++)
		cout<<a[i];
	cout<<endl;


	return 0;
}