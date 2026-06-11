#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(int)(n);i++)

long long gcd(long long p, long long q) {
	if (p < q) swap(p, q);
	if (p % q == 0) return q;
	else return gcd(p / q, p % q);
}
int keta(long long p, int q) {
	if (p / 10 == 0) return q + 1;
	else return keta(p / 10, q + 1);
}
long long kaijo(int p, int q) {
	if (p == 1) return q;
	else return kaijo(p - 1, p * q);
}

int main() {
	long N;
	cin >> N;
	vector<long> vec(N);
	rep(i, N) cin >> vec[i];
	sort(vec.begin(), vec.end());
	pair<long, long> length;
	bool finished = false;
	rep(i, N){
		if (length.first == vec[N - 1 - i]) {
			if (finished == false) { 
				swap(length.first, length.second); 
				finished = true;
			}
			else break;
		}
		else length.first = vec[N - 1 - i];
	}
	cout << length.first * length.second << endl;
}