#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int type1 = a + b;
	int type2 = a + c;
	int type3 = b + c;

	cout << min({ type1,type2,type3 }) << endl;
}




