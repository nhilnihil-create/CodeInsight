//agc017_b.cpp
//Wed Jul 31 21:54:42 2019

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	ll n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;

	for (int i=0;i<=n-1;i++){
		ll bottom = c*(n-1-i)-d*i;
		ll top = d*(n-1-i)-c*i;
		if (b-a>=bottom && b-a<=top){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}