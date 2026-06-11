// abc_046_A.cpp
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
	vector<int> v(3);
	for (int i = 0; i < 3; ++i) cin >> v[i];

	set<int> s(v.begin(), v.end());

	cout << s.size() << "\n";

	return 0;

}
