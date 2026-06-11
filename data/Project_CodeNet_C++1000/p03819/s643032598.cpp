#include<iostream>
#include<math.h>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#include<deque>
#include<vector>

int res[100002];
int bit0[100002];
int bit1[100002];
int sum0(int i);
int sum1(int i);
void add0(int i,int x);
void add1(int i,int x);
int n, m;
using namespace std;
pair<int, pair<int,int>>  line[300000];
int main() {
	//C
	/*long long int x;
	cin >> x;
	long long int y;
	y = x % 11;
	x = x / 11;
	if (y == 0) {
		cout << 2 * x << endl;
	}
	else if (y < 7) {
		cout << 2 * x + 1 << endl;
	}
	else {
		cout << 2 * x + 2 << endl;
	}
	return 0;
	*/

	//D
	/*int n;
	int a[100000];
	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int l, lnum, r, rnum;
	l = 0; lnum = a[l];
	r = n - 1; rnum = a[r];
	//l++;
	//r--;
	int cards = n;
	while (1) {
		l++;
		if (a[l] != lnum) {
			//cout << 1;
			lnum = a[l];
			if (l >= r) {
				cout << cards << endl;
				return 0;
			}
		}
		else {
			while (1) {
				r--;
				if (a[r] != rnum) {
					
					rnum = a[r];
					if (r <= l) {
						cout << cards - 2 << endl;
						return 0;
					}
				}
				else {
					cards = cards - 2;
					if (r <= l) {
						cout << cards << endl;
						return 0;
					}
					break;
				}
			}
		}

	}*/

	//E
	cin >> n >> m;
	int i;
	int j = 0, k;
	for (i = 0; i < n; i++) {
		cin >> line[i].second.first >> line[i].second.second;
		line[i].first = line[i].second.second - line[i].second.first;
	}
	sort(line, line + n);
	for (i = 1; i <= m; i++) {
		while (j < n) {
			if (line[j].first + 1 < i) {
				//累積和に加える
				add0(line[j].second.first, -(line[j].second.first - 1));
				add0(line[j].second.second + 1, line[j].second.second);
				add1(line[j].second.first, 1);
				add1(line[j].second.second + 1, -1);
				j++;
			}
			else {

				break;
			}
		}
		res[i] = res[i] + n - j;
		for (k = 0; k <= m; k = k + i) {
			res[i] = res[i] + sum1(k) * k + sum0(k) - sum1(k - 1) * (k - 1) - sum0(k - 1);
		}
		
	}
	//for (k = 1; k <= m; k++) {
	//	cout << sum1(k) * k + sum0(k) - sum1(k - 1) * (k - 1) - sum0(k - 1) << endl;
	//}

	for (i = 1; i <= m; i++) {
		cout << res[i] << endl;
	}
	return 0;

}
int sum0(int i) {
	int s = 0;
	while (i > 0) {
		s += bit0[i];
		i -= i & -i;
	}
	return s;
}


int sum1(int i) {
	int s = 0;
	while (i > 0) {
		s += bit1[i];
		i -= i & -i;
	}
	return s;
}


void add0(int i, int x) {
	while (i <= m) {
		bit0[i] += x;
		i += i & -i;
	}
}


void add1(int i, int x) {
	while (i <= m) {
		bit1[i] += x;
		i += i & -i;
	}
}

