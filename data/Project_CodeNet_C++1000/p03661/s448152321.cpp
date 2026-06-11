#include<iostream>
#include <cmath>
using namespace std;

int main() {
	int length;
	long long sum = 0;
	cin >> length;
	int *a = new int[length];
	for (int i = 0; i < length; i++) {
		cin >> a[i];
		sum += a[i];
	}
	long long sum1 = a[0];
	long long min = abs(sum - 2 * sum1);
	for (int i = 1; i < length-1; i++) {
		sum1 += a[i];
		if (abs(sum-2*sum1) < min)
			min = abs(sum-2*sum1);
	}
	cout << min ;
}