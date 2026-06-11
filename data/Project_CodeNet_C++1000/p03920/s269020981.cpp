#include<iostream>
#include<string.h>
#include<ctype.h>
#include<string>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define pi 3.141592653589
#define rep(i,a,n) for(int i=a;i<n;i++)
#define INF 1e9
#define LINF 1e17
#define ll long long
#define MOD (int)(1e9+7)
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };



int main() {

	ll n;
	int ans = 0, sum = 0;

	cin >> n;
	while (1) {
		ans++;
		sum += ans;
		if (sum >= n) {
			int tmp = sum - n;
			rep(i, 1, ans  + 1) {
				if (i != tmp)cout << i << endl;
			}
			break;
		}
	}

	return 0;
}