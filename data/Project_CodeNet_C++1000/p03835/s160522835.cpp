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
	int k,s;
	cin>>k>>s;

	int c=0;
	for(int x=0;x<=k;++x){
		for(int y=0;y<=k;++y){
			if(s-x-y>=0&&s-x-y<=k){
				++c;
			}
		}
	}
	cout<<c;
}