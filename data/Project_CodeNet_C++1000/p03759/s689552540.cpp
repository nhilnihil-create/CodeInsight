#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <iomanip>
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define rrep(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
ll mod = 1e9 + 7;

using namespace std;



int main()

{
	int a,b,c;

	cin >>a>>b>>c;

	if ((a - b) == (b - c))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}
