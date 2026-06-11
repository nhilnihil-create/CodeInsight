#include <iostream>
#include<set>
#include<vector>
#include<string>
#include<iterator>
#include<iomanip>
#include<cmath>
#include<map>
#include<string.h>
#include<algorithm>

using namespace std;
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}

int main() {

	ll();

	int a, b, x;
	cin >> x >> a >> b;
	if (abs(x - b) < abs(x - a))
		cout << "B" << endl;
	else
		cout << "A" << endl;

}