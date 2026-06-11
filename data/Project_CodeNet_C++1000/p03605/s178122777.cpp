#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
#include<utility>
#include<map>
using namespace std;
int main() {
	int n; cin >> n;
	if (n % 10 == 9 || n / 10 == 9) cout << "Yes" << endl;
	else cout << "No" << endl;
 	return 0;
}