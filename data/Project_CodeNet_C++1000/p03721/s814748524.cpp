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
	int n;ll k;
	cin>>n>>k;
	map<ll,ll> m;
	fori(n){
		int a,b;
		cin>>a>>b;
		auto itr=m.find(a);
		if(itr!=m.end()){
			m[a]+=b;
		}else{
			m[a]=b;
		}
	}

	for(auto a:m){
		k-=a.second;
		if(k<=0){
			cout<<a.first<<endl;
			return 0;
		}
	}
}