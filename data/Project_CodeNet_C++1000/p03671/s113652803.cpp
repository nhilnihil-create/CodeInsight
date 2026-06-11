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

	int ans1 = a + b;
	int ans2 = a + c;
	int ans3 = b + c;

	cout << min({ ans1,ans2,ans3 }) << endl;
	
}
