#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int main() {
	int H,W,h,w;
	cin >> H >> W >> h >> w;
	int vs[500][500];
	LL sum=0;
	LL u=1e9;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			int v=0;
			if(i%h==h-1&&j%w==w-1){
				v=-u;
			}
			else if(i%h==0&&j%w==0){
				v=u-1;
			}
			vs[i][j]=v;
			sum+=v;
		}
	}
	if(sum>0){
		cout << "Yes" << endl;
		for(int i=0;i<H;i++){
			auto sp="";
			for(int j=0;j<W;j++){
				cout << sp << vs[i][j];
				sp=" ";
			}
			cout <<endl;
		}
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}

