#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int l[100000], r[100000];
	int sum = 0;
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> l[i] >> r[i];
		if(l[i] != r[i]){
			r[i]++;
			sum += r[i] - l[i];
		}
		else if(l[i] == r[i]){
			sum++;
		}
	}
	
	cout << sum << endl;
}