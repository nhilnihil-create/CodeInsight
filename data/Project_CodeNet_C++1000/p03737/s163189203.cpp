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

	string a, b, c;

	cin >> a >> b >> c;

	char s, t, u;

	s = a[0] + ('A'-'a');
	t = b[0] + ('A' - 'a');
	u = c[0] + ('A' - 'a');

	char ans[4];

	ans[0] = s;
	ans[1] = t;
	ans[2] = u;
	ans[3] = '\0';

	cout << ans << endl;

	return 0;
}