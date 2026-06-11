#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < n; ++i)

vector<bool> a(200010), b(200010);

int main(){
	int n, m;
	cin >> n >> m;
	rep(i, m){
		int ia, ib;
		cin >> ia >> ib;
		if(ia == 1) a[ib] = true;
		if(ib == n) b[ia] = true;
	}
	
	for(int i = 2; i < n; ++i){
		if(a[i] && b[i]){
			cout << "POSSIBLE" << endl;
			return 0;
		}
	}
	
	cout << "IMPOSSIBLE" << endl;
	
	return 0;
}

