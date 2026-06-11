#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int INF = 1 << 30;
const long long INFL = 1LL << 60;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100;

int c[N][N], a[N*N];

int main() {
	int h,w,n;cin>>h>>w>>n;
	rep(i,n) cin>>a[i];
	int cur=0;
	rep(k,h*w) {
		int i=k/w, j;
		if (i%2==0) j=k%w;
		else j=w-1-k%w;
		if(a[cur]==0) cur++;
		c[i][j]=cur+1;
		a[cur]--;
	}
	rep(i, h) {
		rep(j, w) {
			cout << c[i][j];
			if (j<w-1) cout << ' ';
		}
		cout << endl;
	}
}
