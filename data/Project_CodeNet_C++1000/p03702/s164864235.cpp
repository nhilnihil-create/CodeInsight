#include "bits/stdc++.h"

using namespace std;

typedef pair<int, int> P;
#define int long long
#define ll long long
#define mod 1000000007
#define INF (1LL<<60)


bool func(int c, vector<int> h, int A, int B){
	int n = h.size();
	for (int i = 0; i < n; i++){
		h[i] -= B*c;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++){
		if (h[i]>0)
			cnt += (int)ceil((double)h[i] / (A - B));
	}
	cerr << c << " " << (cnt <= c ? true : false) << endl;
	if (cnt <= c) return true;
	else return false;
}

signed main(){

	int N, A, B;
	vector<int> h;
	cin >> N >> A >> B;
	int sum = 0;
	for (int i = 0; i < N; i++){
		int t;
		cin >> t;
		h.push_back(t);
		sum += t / B+1;
	}
	sort(h.begin(), h.end(), greater<int>());

	int l = 0, r = sum;
	while (r - l > 1){
		int mid = (r + l) / 2;

		if (func(mid, h, A, B))
			r = mid;
		else
			l = mid;
	}

	if (func(r, h, A, B))
		cout << r << endl;
	else
		cout << l << endl;



	return 0;
}