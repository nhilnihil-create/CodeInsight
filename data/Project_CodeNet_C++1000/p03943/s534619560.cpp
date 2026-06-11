#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#define fore(i,x,y) for(long long i=x;i<y;i++)
typedef long long ll;
using namespace std;
int main()
{
	int a,b,c;
	string s="No";
	cin >> a >> b >> c;
	if(a+b==c)s="Yes";
	if(a+c==b)s="Yes";
	if(b+c==a)s="Yes";
	cout << s << endl;
}