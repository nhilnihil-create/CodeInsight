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
	int n;cin>>n;
	int a[110]={};
	fori(n){cin>>a[i];}
	bool c[8]={};int count=0;
	fori(n){
		if(a[i]<3200){
			c[a[i]/400]=true;
		}else{
			++count;
		}
	}
	int color=0;
	fori(8){color+=(c[i]?1:0);}
	cout<<color+((color==0&&count!=0)?1:0)<<" "<<color+count;
}