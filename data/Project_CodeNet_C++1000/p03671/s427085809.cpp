#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	vector<int> A;
	A.push_back(a);
	A.push_back(b);
	A.push_back(c);

	sort(A.begin(), A.end());
	
	cout << A[0] + A[1] << endl;
}


