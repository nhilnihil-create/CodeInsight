#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	string N;
	cin >> N;

	string N_rev = N;
	reverse(N_rev.begin(), N_rev.end());

	if (N == N_rev) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
