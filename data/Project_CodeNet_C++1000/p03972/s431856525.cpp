#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	long long i,h,w,p,a,b,res,ans=0;
	vector<pair<long long, int>> r;
	cin >> h >> w;
	for(i=0;i<h;i++){
		cin >> p;
		r.push_back(make_pair(p,0));
	}
	for(i=0;i<w;i++){
		cin >> p;
		r.push_back(make_pair(p,1));
	}
	sort(r.begin(),r.end());
	b = h+1;
	a = w+1;
	res = a*b-1;
	i = 0;
	while(res>0){
		if(r[i].second==0){
			ans += (r[i].first)*a;
			res -= a;
			b--;
		}else{
			ans += (r[i].first)*b;
			res -= b;
			a--;
		}
		i++;
	}
	cout << ans << endl;
}
		
		