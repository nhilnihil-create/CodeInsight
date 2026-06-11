
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
#define rep(i, n) for (int i=0; i<(int) (n);i++)
using ll = long long;
using P = pair<int, int>;

void solve_1() {//14m
	int a, b;
	cin >> a >> b;
	int total;
	int n = 0;
	while (!((a-1)*n + 1 >= b)) {
		n++;
	}
	cout << n << endl;

}

void solve_2() {//30m
	int n;
	cin >> n;
	vector<int> x;
	int total = 0;
	rep(i, n) {
		int tmp;
		cin >> tmp;
		x.push_back(tmp);
		total += tmp;
	}
	int p1 = (double(total)/double(n)*2 - 1.0) / 2;
	int p2 = (double(total)/double(n)*2 - 1.0) / 2 + 1;
	int point_sum1 = 0, point_sum2= 0;
	rep(i, n) {
		point_sum1 += pow(x[i] - p1, 2);
		point_sum2 += pow(x[i] - p2, 2);
	}
	cout << min(point_sum1, point_sum2) << endl;

}

void solve_2re() {
	int n;
	cin >> n;
	vector<int> x(n);
	int total = 0;
	rep(i, n) {
		cin >> x[i];
		total += x[i];
	}
	int p1 = total / n;
	int p2 = total / n + 1;
	int point_sum1 = 0, point_sum2 = 0;
	rep(i, n) {
		point_sum1 += pow(x[i] - p1, 2);
		point_sum2 += pow(x[i] - p2, 2);
	}
	cout << min(point_sum1, point_sum2) << endl;
}

void solve_3() {//17m
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	int sum = a + b;
	rep(i, n) {
		if (s[i] == 'a') {
			cout << (sum > 0 ? "Yes" : "No") << endl;
			if (sum>0) {
				sum--;
			}
		}
		else if (s[i] == 'b') {
			cout << (sum > 0 && b > 0 ? "Yes" : "No") << endl;
			if (sum > 0 && b > 0) {
				if (b>0) {
					sum--;
					b--;
				}
				else {
					sum--;
				}
			}
		}
		else if (s[i] == 'c') {
			cout << "No" << endl;
		}
	}
}

void solve_4() {

}

void solve_5() {

}

void solve_6() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//solve_1();
	//solve_2();
	//solve_2re();
	solve_3();
	//solve_4();
	//solve_5();
	//solve_6();
	return 0;
}