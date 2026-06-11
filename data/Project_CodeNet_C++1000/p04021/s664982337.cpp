#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	UL N;
	
	void Solve() {
		cin >> N;
		deque<UL> A1, A2;
		rep(i, N) {
			UL a; cin >> a;
			if (i % 2 == 1) A1.push_back(a);
			else A2.push_back(a);
		}
		sort(A1.begin(), A1.end());
		sort(A2.begin(), A2.end());
		A1.push_back(1000000001);
		A2.push_back(1000000001);
		UL Movs = 0;
		rep(i, N) {
			deque<UL> *posi, *neg;
			if (i % 2 == 1) { posi = &A1; neg = &A2; }
			else { posi = &A2; neg = &A1; }
			if (posi->front() <= neg->front()) {
				posi->pop_front();
			}
			else {
				neg->pop_front();
				Movs++;
			}
		}
		cout << Movs / 2 << endl;
	}


	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}
