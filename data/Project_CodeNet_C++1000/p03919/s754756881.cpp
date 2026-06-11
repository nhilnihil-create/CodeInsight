#include<iostream>
#include<cstdio>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<map>
#include<numeric>
#include<queue>
#include<functional>
#include<cassert>
#include<set>
#define rep(a,b) for(int a=0;a<b;++a)
#define REP(a,b,c,d) for(int a=b;a<c;a+=d)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define mod 1000000007
using namespace std;
using ll = long long;
using p_i = pair<int, int>;
int main() {
	int H, W; cin >> H >> W;
	rep(i, H) {
		rep(j, W) {
			string str;
			cin >> str;
			if (str == "snuke") {
				cout << (char)('A' + j) << i + 1 << endl;
				return 0;
			}
		}
	}
}