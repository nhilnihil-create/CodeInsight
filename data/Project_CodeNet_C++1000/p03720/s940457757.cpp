#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> vec(N);
	for (int i = 0; i < M; i++){
    	int x1, x2;
    	cin >> x1 >> x2;
    	vec.at(x1 - 1) += 1;
    	vec.at(x2 - 1) += 1;
    }
  	for (int i = 0; i < N; i++){
    	cout << vec.at(i) << endl;
    }
}