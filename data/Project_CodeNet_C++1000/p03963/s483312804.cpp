#include <iostream>
#include <vector>
#include<map>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
using namespace std;


int main() {
	long long int sum;
	int n, k;
	cin >> n >> k;
	sum = k * pow(k - 1, n - 1);
	cout << sum;
}