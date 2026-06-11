#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

int w,h;
long long ww[100005];
long long hh[100005];

int main(){
	cin>>w>>h;
	for(int i=0;i<w;i++) cin>>ww[i];
	for(int i=0;i<h;i++) cin>>hh[i];

	sort(ww,ww+w);
	sort(hh,hh+h);

	ww[w] = 10000000000LL;
	hh[h] = 10000000000LL;

	int wp = 0;
	int hp = 0;

	long long ans = 0;

	for(int i=0;i<w+h;i++){
		if(ww[wp] < hh[hp]) {
			ans += ww[wp] * (h - hp + 1);
			wp++;
		} else if(hh[hp] < ww[wp]){
			ans += hh[hp] * (w - wp + 1);
			hp++;
		} else {
			if(hp > wp){
				ans += ww[wp] * (h - hp + 1);
				wp++;
			} else {
				ans += hh[hp] * (w - wp + 1);
				hp++;
			}
		}
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;

}