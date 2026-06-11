#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; ++i)

int main(){
	int n;
	cin >> n;
	vector<int> vi(n), b;
	rep(i, n){
		cin >> vi[i];
	}

	std::reverse(vi.begin(), vi.end());

	for(int i = 0; i < n; i += 2){
		b.emplace_back(vi[i]);
	}
		
	int len = n - 1;
	if(n % 2 != 0){
		len--;
	}
	
	for(int i = len; i >= 0; i -= 2){
		b.emplace_back(vi[i]);
	}
	
	rep(i, n){
 		cout << b[i] << " ";
	}
	cout << endl;
	
	return 0;
}

