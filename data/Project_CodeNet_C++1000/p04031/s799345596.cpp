#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> a = vector<int>(N);
	for(int i=0;i<N;i++){
		cin >> a.at(i);
	}
	sort(a.begin(), a.end());

	int answer = 100000000000;
	int tmp;

	for(int x=a.at(0);x<=a.at(N-1);x++){
		tmp = 0;
		for(auto num : a){
			tmp += (num - x) * (num - x);
		}
		if(answer > tmp){
			answer = tmp;
		}
	}

	cout << answer << endl;

}
