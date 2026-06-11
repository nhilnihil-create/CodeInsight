#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define PI 3.141592653589793238
#define INF 1050000000

using vi = vector<int>;


int main() {

	int N;

	cin >> N;

	int A;

	cin >> A;


	cout << N*N-A << endl;

	return 0;
}