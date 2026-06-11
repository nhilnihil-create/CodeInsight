#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, W;
	cin >> N >> W;
	priority_queue<long long> W1;
	priority_queue<long long> W2;
	priority_queue<long long> W3;
	priority_queue<long long> W4;
	long long memoW = 0;
	for (int i = 0;i<N;++i) {
		long long w, v;
		cin >> w >> v;
		if (0 == i) {
			memoW = w;
		}
		if (memoW == w) {
			W1.push(v);
		}
		else if (memoW +1 ==w) {
			W2.push(v);
		}
		else if (memoW+2 ==w) {
			W3.push(v);
		}
		else {
			W4.push(v);
		}
	}
	vector<long long>Sum1(W1.size()+1,0); 
	for (long long i = 0;i< Sum1.size()-1;++i) {
		int x = W1.top();
		W1.pop();
		Sum1[i + 1] = Sum1[i] + x;
	}
	vector<long long>Sum2(W2.size() + 1, 0);
	for (long long i = 0; i < Sum2.size() - 1; ++i) {
		int x = W2.top();
		W2.pop();
		Sum2[i + 1] = Sum2[i] + x;
	}
	vector<long long>Sum3(W3.size() + 1, 0);
	for (long long i = 0; i < Sum3.size() - 1; ++i) {
		int x = W3.top();
		W3.pop();
		Sum3[i + 1] = Sum3[i] + x;
	}
	vector<long long>Sum4(W4.size() + 1, 0);
	for (long long i = 0; i < Sum4.size() - 1; ++i) {
		int x = W4.top();
		W4.pop();
		Sum4[i + 1] = Sum4[i] + x;
	}
	long long ans = 0;
	for (long long i = 0; i < Sum1.size(); ++i) {
		for (long long j= 0; j < Sum2.size(); ++j) {
			for (long long k = 0; k < Sum3.size(); ++k) {
				for (long long l = 0; l < Sum4.size(); ++l) {
					long long x = memoW * i + (memoW + 1)*j + (memoW+2)*k + (memoW + 3)*l;
					if (x<=W) {
						long long y = Sum1[i] + Sum2[j] + Sum3[k] + Sum4[l];
						ans = max(ans, y);
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
