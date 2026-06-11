#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <bitset>
#include <vector>
#include <queue>
#include <map>

#define i64 int64_t
#define ff(ii,nn,mm) for(int ii=nn;ii<mm;ii++)
#define sort(vvv) sort(vvv.begin(),vvv.end())
#define rvs(vvv) reverse(vvv.begin(),vvv.end())
int inf = 1000000007;

using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	int n;
	cin >> n;
	deque<int> data;
	ff(i, 1, n+1) {
		int a;
		cin >> a;
		ff(j, 0, a) {
			data.push_back(i);
		}
	}
	ff(y, 0, h) {
		vector<int> line(w);
		ff(x, 0, w) {
			if (y % 2 == 1) {
				line.at(w - 1 - x) = data.front();
			}
			else {
				line.at(x) = data.front();
			}
			data.pop_front();
		}
		cout << line.at(0);
		ff(k, 1, w) {
			cout << " " << line.at(k);
		}
		cout << endl;
	}
	return 0;
}