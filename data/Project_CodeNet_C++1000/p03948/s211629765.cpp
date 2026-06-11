#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(void){
	int N,T; cin >> N >> T;
	vector<int> A(N);
	for (auto &a : A) cin >> a;
	vector<pair<int, int > > mi(N);
	vector<pair<int, int > > ma(N);

	mi[0] = make_pair(A[0], 0);
	for(int i=1;i<N;++i){
		mi[i] = min(mi[i-1], make_pair(A[i], i));
	}

	ma[N-1] = make_pair(A[N-1], N-1);
	for(int i=N-2;i>=0;--i){
		ma[i] = max(ma[i+1], make_pair(A[i], i));
	}

	int maxVal = 0;
	for(int i=0;i<N-1;++i){
		int value = ma[i+1].first - mi[i].first;
		maxVal = max(maxVal, value);
	}

	vector<int> maxIndex;
	vector<bool> isChecked(N);
	for(int i=0;i<N-1;++i){
		int value = ma[i+1].first - mi[i].first;
		if(value == maxVal){
			isChecked[ma[i+1].second] = true;
			isChecked[mi[i].second] = true;
		}
	}

	int res = 0;
	for(int i=0;i<N;++i){
		res += (isChecked[i]);
	}
	cout << res/2 << endl;
	return 0;
}