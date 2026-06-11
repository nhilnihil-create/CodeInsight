#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <climits>
#include <cstring>

using namespace std;

#define int long long
#define rep(i, n) for (int i=0;i<(int)(n);++i)
#define rep1(i, n) for (int i=1;i<=(int)(n);++i)
#define range(i, l, r) for (int i=l;i<(int)(r);++i)
#define rrange(i, l, r) for (int i=r-1;i>=(int)(l);--i)
#define unless(a) if(!(a))
#define all(a) begin(a),end(a)
#define fst first
#define scd second
#define PB emplace_back
#define PPB pop_back

using vi=vector<int>;
using pii=pair<int, int>;
using ll=long long;

bool chmin(int&a,int b){return a>b?(a=b,true):false;}
bool chmax(int&a,int b){return a<b?(a=b,true):false;}
int read(){int a;scanf("%lld",&a);return a;}

const int mod = 1e9 + 7;

int N;
int counter[100010];

signed main()
{
	cin >> N;

	vi A(N);

	rep(i, N) {
		cin >> A[i];
	}

	sort(all(A));

	rep(i, N) {
		counter[A[i]]++;
	}

	int one = 0, two = 0;
	range(i, 1, 100001) {
		if (counter[i] > 0) {
			counter[i] = 2 - counter[i] % 2;
			if (counter[i] == 1) one++;
			else two++;
		}
	}

	one += two / 2 * 2;

	cout << one << endl;
}

