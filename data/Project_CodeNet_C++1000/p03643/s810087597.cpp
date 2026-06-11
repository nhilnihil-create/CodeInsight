#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

#define PI 3.141592653589793238
#define INF 1050000000

using namespace std;



//cout << fixed << setprecision(15) << << endl;
//cout << << endl;

int main() {

	int N;

	cin >> N;

	char a = N % 10 + '0';
	char b = (N / 10) % 10 + '0';
	char c = N / 100 + '0';

	string ans = "ABC";

	ans += c;
	ans += b;
	ans += a;

	cout << ans << endl;

	return 0;
}
