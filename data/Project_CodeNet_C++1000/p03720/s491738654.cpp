#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
	int city;
	int road, a, b;
	cin >> city >> road;
	int road_sum[city] = {};
	for (int i = 0; i < road; i++) {
		cin >> a >> b;
		road_sum[a-1]++;
		road_sum[b-1]++;
	}
	for (int i = 0; i < city; i++) {
		cout << road_sum[i] << endl;
	}
}
