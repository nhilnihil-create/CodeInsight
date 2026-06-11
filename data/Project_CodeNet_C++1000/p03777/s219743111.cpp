#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	char a, b;
	cin >> a >> b;

	if (a == 'H') {
		//AtCoDeerくん→正直者
		if (b == 'H') {
			//TopCoDeer君→正直
			cout << "H" << endl;
		}
		else {
			//TopCoDeer君→うそつき
			cout << "D" << endl;
		}
	}
	else {
		//AtCoDeerくん→うそつき
		if (b == 'H') {
			//TopCoDeer君→正直
			cout << "D" << endl;
		}
		else {
			//TopCoDeer君→うそつき
			cout << "H" << endl;
		}
	}



}
