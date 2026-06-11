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

	set<int> N;
	N.insert(a);
	N.insert(b);
	N.insert(c);

	cout << N.size() << endl;
	
	
}
