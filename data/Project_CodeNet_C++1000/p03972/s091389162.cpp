#include "bits/stdc++.h"
using namespace std;

struct PR {
	int Par;
	int Rank;
};

struct route {
	long long Cost;
	int From;
	int To;
	int WH;
};

static PR PRW[100010], PRH[100010];

void init(int X, PR pr[]) {
	for (int i = 0; i <= X; i++) {
		pr[i].Par = i;
		pr[i].Rank = 0;
	}
}

int root(int X, PR pr[]) {
	if (pr[X].Par == X) return X;
	else return pr[X].Par = root(pr[X].Par, pr);
}

void unite(int X, int Y, PR pr[]) {
	X = root(X, pr), Y = root(Y, pr);
	if (pr[X].Rank < pr[Y].Rank) pr[X].Par = Y;
	else {
		pr[Y].Par = X;
		if (pr[X].Rank == pr[Y].Rank) pr[X].Rank++;
	}
}

bool same(int X, int Y, PR pr[]) {
	return root(X, pr) == root(Y, pr);
}

int main() {
	static long long W, H, A, B, P, Q, ANS = 0;
	auto SORT = [](route R1, route R2) {return R1.Cost > R2.Cost; };
	priority_queue<route, vector<route>, decltype(SORT)> PQ(SORT);
	cin >> W >> H;
	A = W + 1, B = H + 1;
	init(W, PRW);
	init(H, PRH);
	for (int i = 0; i < W; i++) cin >> P, PQ.push(route{ P, i, i + 1, 1 });
	for (int i = 0; i < H; i++) cin >> Q, PQ.push(route{ Q, i, i + 1, 2 });
	while (!PQ.empty()) {
		route R = PQ.top();
		PQ.pop();
		if (R.WH == 1) {
			if (!same(R.From, R.To, PRW)) {
				ANS += R.Cost * B;
				A--;
				unite(R.From, R.To, PRW);
			}
		}
		else {
			if (!same(R.From, R.To, PRH)) {
				ANS += R.Cost * A;
				B--;
				unite(R.From, R.To, PRH);
			}
		}
	}
	cout << ANS;
}