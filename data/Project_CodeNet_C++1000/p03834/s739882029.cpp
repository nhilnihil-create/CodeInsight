#include <iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

int main() {
	string str;
	cin >> str;

	str = str.replace(5, 1, " ");
	str = str.replace(13, 1, " ");

	cout << str << endl;

	return 0;
}