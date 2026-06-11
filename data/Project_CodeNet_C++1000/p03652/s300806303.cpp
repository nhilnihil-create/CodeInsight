#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int a[310][310];
int main(){
	int n,m;
	cin >> n >> m;
	vector<int> id(n);
	vector<bool> used(m+1);
	int res = n;
	rep(i,n){
		rep(j,m)cin >> a[i][j];
	}
	rep(i,m){
		vector<int> p(m+1);
		for(int j=0;j<n;j++){
			while(used[a[j][id[j]]]){
				id[j]++;
				if(id[j]>=m){
					goto yeah;
				}
			}
			p[a[j][id[j]]]++;
		}
		int nid = -1;
		int mx = 0;
		rep(j,m+1){
			if(mx<p[j]){
				mx = p[j];
				nid = j;
			}
		}
		res = min(res,mx);
		used[nid] = 1;
	}
yeah:
	cout << res << endl;
	return 0;
}