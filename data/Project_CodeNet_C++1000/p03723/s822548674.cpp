#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>
#include <queue>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=100100;

int main() {
	ll a,b,c;
	cin>>a>>b>>c;
	ll num=0;
	while(true){
		if(a%2==1||b%2==1||c%2==1){
			cout<<num;return 0;
		}
		if(a==b&&b==c){
			cout<<-1;return 0;
		}
		++num;
		ll x,y,z;
		x=(b/2+c/2);y=(a/2+c/2);z=(a/2+b/2);
		a=x;b=y;c=z;
	}
}