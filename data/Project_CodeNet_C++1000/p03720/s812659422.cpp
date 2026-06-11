#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  	int N, M, x;
    cin >> N >> M;
    vector<int> A(N);
    for (int i=0; i<2*M; i++){
    	cin >> x;
    	A[x-1]++;
    }
    for (int i=0; i<N; i++){
    	cout << A[i] << endl;
    }
}