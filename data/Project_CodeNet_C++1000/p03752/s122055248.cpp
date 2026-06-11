#include<iostream>
#include<algorithm>
#include<vector>
using ll = long long;
using namespace std;

constexpr ll INFI = 1e18;

ll calc(int n, int k, vector<int> v, int* a);

int main() {
	int n, k;
	ll lcost;
	ll cost;
	cin >> n >> k;
	int* a = new int[n];
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	vector<int> v;
	v.push_back(0);
	cout << calc(n, k, v, a) << endl;

}

ll calc(int n, int k, vector<int> v, int* a) {
	if (v.size() == k) {
		int index = 0;
		int height = 0;
		ll cost = 0;
		for (int i = 0;index<k;i++) {
			if (v[index] == i) {
				if (a[i] > height) {
					height = a[i];
				}
				else {
					height++;
					cost += height - a[i];
				}
				index++;
			}
			else {
				if (a[i] > height) {
					height = a[i];
				}
			}
		}
		return cost;
	}else {
      	ll mi=INFI;
		for (int i = v[v.size() - 1] + 1;i < n;i++) {
			vector<int> v2(v);
			v2.push_back(i);
			mi = min(mi,calc(n, k, v2, a));
		}
		return mi;
	}
}