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
	int X; cin >> X;
	for (int i = 1; i <= X; ++i) {
		if (i*(i + 1) / 2 >= X) {
			cout << i << endl;
			break;
		}
	}
	cin >> X;
}