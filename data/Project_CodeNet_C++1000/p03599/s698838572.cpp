#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)


using namespace std;



int main() {
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;

	cin >> a >> b >> c >> d >> e >> f;

	int min_op = 1000000;
	double max_con = 0;
	int max_total = 0;
	int max_suger = 0;

	for (int ca = 0; ca <= 30; ca++) {
		for(int cb = 0; cb <= 30; cb++) {
			if (ca == 0 && cb == 0) {
				continue;
			}
			for(int cc = 0; cc <= 3000; cc++) {

					int total = ca * 100 * a + cb * 100 * b 
						+ cc * c;

					if (total > f) {
						break;
					}


					if (cc * c > e * (ca * a + cb * b)) {
						break;
					}

					int cd1 = (f - total) / d; 
					int cd2 = (e * (ca * a + cb * b) - cc * c) / d;
					int cd = max(min(cd1, cd2), 0); 

					total += cd * d;

					int suger =  cc * c + cd * d;		

					double cur_con =  (double) suger /  (double) total;
					int op = ca + cb + cc + cd;
					if (cur_con > max_con) {

						max_con = cur_con;
						min_op = op;
						max_total = total;
						max_suger = suger;

					}
					if (cur_con == max_con && min_op > op) {

						max_con = cur_con;
						min_op = op;
						max_total = total;
						max_suger = suger;
					}
				//}
			}

		}
	} 
	cout << max_total << " " << max_suger << endl;

	return 0;

}