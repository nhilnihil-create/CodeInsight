#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>
using ll = long long;
using namespace std;
using pii = pair<int, int>;
using pdi = pair<double, int>;

int N, L, T;
vector<int> X;
vector<int> W;

int main() {
	cin >> N >> L >> T;
	for (int i = 0; i < N; i++)
	{
		int tmpX;
		int tmpW;
		cin >> tmpX >> tmpW;
		X.push_back(tmpX);
		W.push_back(tmpW);
	}

	vector<int> rX, lX;
	for (int i = 0; i < N; i++)
	{
		if (W.at(i) == 1) {
			rX.push_back(X.at(i));
		}
		else {
			lX.push_back(X.at(i));
		}
	}
	reverse(rX.begin(), rX.end());

	const int q = T / L;
	const int r = T % L;

	int t;
	int x;
	int w;
	int rcnt, lcnt;
	const int rcnt_end = rX.size(), lcnt_end = lX.size();

	t = 0;
	x = X.at(0);
	w = W.at(0);
	rcnt = 0;
	lcnt = 0;
	if (w == 1) {
		rcnt = rcnt_end - 1;
	}

	int x_final;
	int kasanari = -1;
	int kasanari_final = -1;
	bool is_final = false;
	while (true) {
		int y;
		int dt, dx;
		if (w == 1) {
			if (lcnt_end > 0) {
				y = lX.at(lcnt) - t;
				y += L;
				y %= L;

				if (x <= y) {
					dt = (y - x + 1) / 2;
					dx = (y - x) / 2;
				}
				else {
					dt = (y + L - x + 1) / 2;
					dx = (y + L - x) / 2;
				}
			}
			else {
				dt = L;
				dx = 0;
			}
			if (!is_final && t + dt > r) {
				x_final = x + r - t;
				x_final %= L;
				is_final = true;
			}
			if (t + dt > L) {
				x += L - t;
				x %= L;
				break;
			}
			x += dx;
			x %= L;
			t += dt;
			rcnt++;
			rcnt %= rcnt_end;
			if (lcnt_end > 0)
				w = 2;
		}
		else {
			if (rcnt_end > 0) {
				y = rX.at(rcnt) + t;
				y %= L;

				if (y <= x) {
					dt = (x - y + 1) / 2;
					dx = -((x - y) / 2);
				}
				else {
					dt = (x + L - y + 1) / 2;
					dx = -((x + L - y) / 2);
				}
				if (!is_final && t + dt == r) {
					if (y <= x) {
						if ((x - y) % 2 == 0) {
							kasanari_final = 1;
						}
					}
					else {
						if ((x + L - y) % 2 == 0) {
							kasanari_final = 1;
						}
					}
				}
				if (t + dt == L) {
					if (y <= x) {
						if ((x - y) % 2 == 0) {
							kasanari = 1;
						}
					}
					else {
						if ((x + L - y) % 2 == 0) {
							kasanari = 1;
						}
					}
				}
			}
			else {
				dt = L;
				dx = 0;
			}
			if (!is_final && t + dt > r) {
				x_final = x - (r - t);
				x_final %= L;
				x_final += L;
				x_final %= L;
				is_final = true;
			}
			if (t + dt > L) {
				x -= L - t;
				x %= L;
				x += L;
				x %= L;
				break;
			}
			x += dx;
			x %= L;
			x += L;
			x %= L;
			t += dt;
			lcnt++;
			lcnt %= lcnt_end;
			if (rcnt_end > 0)
				w = 1;
		}
	}

	int did;
	for (int i = 0; i < N; i++)
	{
		if (x == X.at(i)) {
			did = i;
			if (kasanari == 1) {
				did++;
			}
			break;
		}
	}

	vector<int> finalx;
	for (int i = 0; i < N; i++)
	{
		int tmpfinalx;
		if (W.at(i) == 1) {
			tmpfinalx = X.at(i) + r;
		}
		else {
			tmpfinalx = X.at(i) - r;
		}
		tmpfinalx %= L;
		tmpfinalx += L;
		tmpfinalx %= L;
		finalx.push_back(tmpfinalx);
	}
	sort(finalx.begin(), finalx.end());

	int did_final;
	for (int i = 0; i < N; i++)
	{
		if (finalx.at(i) == x_final) {
			did_final = i;
			if (kasanari_final == 1) {
				did_final++;
			}
			break;
		}
	}
	const int id_final = (q*did + did_final) % N;
	for (int i = id_final; i < N; i++)
	{
		cout << finalx.at(i) << endl;
	}
	for (int i = 0; i < id_final; i++)
	{
		cout << finalx.at(i) << endl;
	}

	return 0;
}
