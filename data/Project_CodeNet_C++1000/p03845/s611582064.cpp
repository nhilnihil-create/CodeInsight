#include <vector>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n; cin >> n;
	vector<int> probs;
	for(int i{}; i<n; i++){
		int b; cin >> b;
		probs.push_back(b);
	}

	int m; cin >> m;
	for(int i{}; i<m; i++){
		int p,x,temp;
		cin >> p >> x;
		temp = probs[p-1];
		probs[p-1] = x;
		int sum{};

	for(int j{}; j<n; j++){
		sum+=probs[j];
	}
		cout << sum << "\n";
		probs[p-1]=temp;
	}










 return 0;
}
