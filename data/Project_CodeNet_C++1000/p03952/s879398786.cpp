#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define rrep(i,n) RFOR(i,n,0)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;

	if(n == 2){
		if(x == 2){
			cout << "Yes" << endl;
			cout << "1" << endl;
			cout << "2" << endl;
			cout << "3" << endl;
		}else{
			cout << "No" << endl;
		}
		return 0;
	}

	if(x == 1 || x == 2*n -1){
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;

	multiset<int> ms;
	rep(i, 2*n-1) ms.insert(i+1);

	if(x != 2*n - 2){
		ms.erase(x+2);
		ms.erase(x-1);
		ms.erase(x);
		ms.erase(x+1);

		auto itr = ms.begin();
		rep(i, 2 * n - 1){
			if(i < n - 3 || n < i){
				cout << *itr << endl;
				itr++;
			}else if(i == n - 3){
				cout << x+2 << endl;
			}else if(i == n - 2){
				cout << x-1 << endl;
			}else if(i == n - 1){
				cout << x << endl;
			}else if(i == n){
				cout << x+1 << endl;
			}
		}
	}else{
		ms.erase(x-1);
		ms.erase(x+1);
		ms.erase(x);
		ms.erase(x-2);

		auto itr = ms.begin();
		rep(i, 2 * n - 1){
			if(i < n - 3 || n < i){
				cout << *itr << endl;
				itr++;
			}else if(i == n - 3){
				cout << x-1 << endl;
			}else if(i == n - 2){
				cout << x+1 << endl;
			}else if(i == n - 1){
				cout << x << endl;
			}else if(i == n){
				cout << x-2 << endl;
			}
		}
	}
}
