#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9+7;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a.at(i);
	}
	vector<int> num(100100);
	for(int i=0; i<100100; i++){
		num.at(i) = 0;
	}
	for(int i=0; i<n; i++){
		num.at(a.at(i))++;
	}
	int diff=0;
	int even=0;
	for(int i=0; i<100100; i++){
		if(num.at(i) > 0){
			diff++;
			if(num.at(i)%2==0){
				even++;
			}
		}
	}
	cout << (even%2==0?diff:diff-1) << endl;
}