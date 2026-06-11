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
	int A,B,C;

	cin >> A >> B>>C;
	bool flg = false;

	if ((A <= C) && (C <= B))
	{
		flg = true;
	}
	
	
	if (flg)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No"<< endl;
	}
	

	return 0;
	
}