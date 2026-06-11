#include <iostream>

using namespace std;

int main() {

	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int upper_base, lower_base, height;
		cin >> upper_base >> lower_base >> height;

	int trapezoid_area = 0;
		trapezoid_area = ((upper_base + lower_base) * height / 2);

	cout << trapezoid_area << endl;


	return 0;
}