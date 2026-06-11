#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)





#define rrep(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
ll N;
//-----------------------------------------------------------------------------------
int main() {
	cin >> N;
	N++;

	int d = 0;
	ll n = N;
	while (0 < n) n /= 2, d++;

	deque<int> deq;
	ll cur = 1; int num = 1;
	rrep(i, d - 2, 0) {
		deq.push_back(num); num++;
		cur *= 2;

		if (((cur + 1) << i) <= N) {
			deq.push_front(num);
			num++;
			cur++;
		}
	}

	cout << 80 + deq.size() << endl;
	rep(i, 0, 80) printf("%d ", i + 1);
	for (int i : deq) printf("%d ", i);

	cout << endl;
}