#include <bits/stdc++.h>
using namespace std;
/**
  2 2 3 
4 1 2 3 5
  **/
int main(){
	int n, x; cin >> n >> x;
	if(n == 2){
		if(x == 2){
			cout << "Yes" << endl;
			cout << 1 << endl;
			cout << 2 << endl;
			cout << 3 << endl;
		} else {
			cout << "No" << endl;
		}
	} else {
		n = 2 * n - 1;
		if(x != 1 && x != n){
			cout << "Yes" << endl;
			vector<int> a, tk(n + 10, 0);
			tk[x - 1] = 1;
			tk[x - 2] = 1;
		       	tk[x] = 1;
			tk[x + 1] = 1;
			tk[x + 2] = 1;
			for(int i = 1; i <= n; i++) if(!tk[i]) a.push_back(i);
			int len = a.size();
			for(int i = 0; i < len/2; i++) cout << a[i] << endl;
			if(x - 2 >= 1 && x + 2 <= n){
				cout << x + 2 << endl;
				cout << x - 1 << endl;
				cout << x << endl;
				cout << x + 1 << endl;
				cout << x - 2 << endl;
			} else if(x + 2 <= n){
				cout << x + 2 << endl;
				cout << x - 1 << endl;
				cout << x << endl;
				cout << x + 1 << endl;
			} else {
				cout << x - 2 << endl;
				cout << x + 1 << endl;
				cout << x << endl;
				cout << x - 1 << endl;
			}
			for(int i = len/2; i < len; i++) cout << a[i] << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}
