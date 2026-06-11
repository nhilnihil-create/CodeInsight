#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
	}

	double ave = 0;
	int Ave = 0;
	for (int i = 0; i < N; i++) {
		ave += A.at(i);
	}
	ave = ave / N;
  if (ave > 0)
    ave += 0.5;
  else ave += -0.5;
	Ave = ave;

	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += (A.at(i) - Ave) * (A.at(i) - Ave);
	}
	cout << sum;

	return 0;
}