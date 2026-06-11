#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

namespace {

}

int main()
{
	std::string s;

	int A = 0, B = 0;

	cin >> A >> B;

	int start = A + B;

	if (start > 23){
		start -= 24;
	}

	cout << start;

	return 0;
}
