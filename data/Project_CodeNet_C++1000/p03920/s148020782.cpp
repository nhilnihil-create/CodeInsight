#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ld long double

using namespace std;

const int MIN = 1e3 + 2;
const int MXN = 1e5 + 3;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 15;
const double EPS = 1e-9;

int ans = 0;
int id;
int sum;
int n;

int main(){
	cin >> n;
	for (int i = 1;; i++){
		if (ans + i == n){
			ans += i;
			id = i;
			break;
		}
		if (ans + i > n){
			id = i;
			break;
		}
		ans += i;
	}
	if (ans == n){
		for (int i = 1; i <= id; i++){
			cout << i << " ";
		}
		return 0;
	}
	for (int i = 1; i <= id; i++){	
		if (n - ans == id - i)
			continue;
		cout << i << " ";
	}
	return 0;
}