#include <bits/stdc++.h>
using namespace std;
#define int long long
//using lint =long long;

signed main(){
	int h,w,n;cin>>h>>w>>n;
	map<pair<int,int>,int>cnt;
	for(int i=0;i<n;i++){
		int x,y;
		cin >>x>>y;	
	for(int j=0;j<3;j++){
	for(int k=0;k<3;k++){
		int x0,y0;
		x0=x-j;y0=y-k;
		if(1<=x0 && x0+2<=h && 1<=y0 && y0+2<=w)
        {pair<int,int> z=make_pair(x0,y0);
        cnt[z]++;}
      
	}
	}
	}
	vector<int>ans(10,0);
	for(auto&& w:cnt){
		ans[w.second]++;
	}
	
	int tmp=accumulate(begin(ans),end(ans),0ll);
	ans[0]=(h-2)*(w-2)-tmp;
	for(auto&& w:ans)cout<<w<<endl;

}
