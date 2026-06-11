#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<complex>
#include<math.h>
using namespace std;
typedef long long int llint;
typedef vector<int> vint;
typedef vector<llint> vllint;
typedef vector<pair<int, int>> vpint;
typedef vector<pair<llint, llint>> vpllint;
#define rep(i,n) for(int i=0;i<n;i++)
#define yes(ans) if(ans)cout<<"yes"<<endl;else cout<<"no"<<endl;
#define Yes(ans) if(ans)cout<<"Yes"<<endl;else cout<<"No"<<endl;
#define YES(ans) if(ans)cout<<"YES"<<endl;else cout<<"NO"<<endl;
#define POSSIBLE(ans) if(ans)cout<<"POSSIBLE"<<endl;else cout<<"IMPOSSIBLE"<<endl;

bool check(int a, int b) {
	return a > b;
}

int main() {
	int n;
	cin >> n;
	vector<bool>a(n, false);
	int cnt = 0;
	rep(i, n + 1) {
		if (i == 0) {
			continue;
		}
		cnt += i;
		a[i - 1] = true;
		if (n < cnt) {
			a[cnt - n - 1] = false;
			break;
		}
		if (n == cnt) {
			break;
		}
	}
	rep(i, n) {
		if (a[i]) {
			cout << i + 1 << endl;
		}
	}
	return 0;
}
