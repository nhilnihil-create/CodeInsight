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
	string a,b,c;
	cin >> a >> b >> c;
	if(*(a.end()-1)==*(b.begin())&&*(b.end()-1)==*(c.begin())){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}