
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<utility>
using namespace std;
#define REP(i, a,b) for(i=a;i<b;i++) 
#define output(x) cout<<x<<endl;
typedef long long int ll;



int main()
{
	ll  i, j, k, l, m, sum, flag,ans,W,H,N,h,w;
	sum = 0;
	flag = 0;
	cin >> H >> W >> h >> w;
	if (H%h == 0 && W%w == 0) {
		output("No");
		return 0;
	}
	if (W%w != 0) {
		vector<ll>S(W + 1);
		S[0] = 0;
		for (j = 1; j <= w-1; j++) {
			if (W%w == j) {
				S[j] = W / w + 1;
			}
			else {
				S[j] = 100;
			}
		}
		for (j = w; j < W + 1; j++) {
			S[j] = S[j - w] - 1;
		}
		vector<ll>a(W);
		REP(i, 0, W) {
			a[i] = S[i + 1] - S[i];
		}
output("Yes");
		REP(j, 0, H) {
			REP(i, 0, W) {
				cout << a[i] << " ";
			}
			cout << endl;
		}
		return 0;


	}
	vector<ll>S1(H + 1);
	S1[0] = 0;
	for (j = 1; j <= h - 1; j++) {
		if (H%h == j) {
			S1[j] = H / h + 1;
		}
		else {
			S1[j] = 100;
		}
	}
	for (j = h; j < H + 1; j++) {
		S1[j] = S1[j - h] - 1;
	}
	vector<ll>b(H);
	REP(i, 0, H) {
		b[i] = S1[i + 1] - S1[i];
	}
output("Yes");
	REP(i, 0, H) {
		REP(j, 0, W) {
			cout << b[i] << " ";
		}
		cout << endl;
	}

	return 0;
}

