#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
	int N,A,B,a=0,b=0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		if (a < A) {
			b = B;
			a = A;
		}
	}
	cout << b + a;
}