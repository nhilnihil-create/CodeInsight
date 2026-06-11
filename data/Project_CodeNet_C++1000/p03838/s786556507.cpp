#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

#define fori(x) for (int i = 0; i < x; ++i)
#define forj(x) for (int j = 0; j < x; ++j)

typedef long long ll;

const int INF = 2e9 + 5;
const int alength=200000;

int main() {
	ll x,y;
    cin>>x>>y;
    ll a=INF;

	if(x<=y){
		//++
		a=y-x;
	}
	if(-x<=y){
		//-+
		a=min(a,1+y+x);
	}
	if(x<=-y){
		//+-
		a=min(a,1-y-x);
	}
	if(-x<=-y){
		//--
		a=min(a,2-y+x);
	}

    cout<<a;
}