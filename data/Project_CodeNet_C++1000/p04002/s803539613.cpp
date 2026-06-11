#include <bits/stdc++.h>
#define int     int64_t
#define ii      pair<int,int>
#define pb      push_back
using namespace std;

int32_t main() {
    std::ios::sync_with_stdio(false);
	int h,w,n; cin >> h >> w >> n;
	set<ii> st;
	for(int i=0,a,b;i<n;i++){
	    cin >> a >> b; --a, --b;
	    st.insert({a,b});
	}
	vector<int> hist(10,0);
	for(auto &cell : st){
	    for(int i=0;i<3;i++){
	        for(int j=0;j<3;j++){
	if(cell.first - i < 0 || cell.second - j < 0 || cell.first - i + 2 >= h || cell.second - j + 2 >= w) continue;
	           int sum = 0;
	           for(int x=0;x<3;x++){
	               for(int y=0;y<3;y++) sum += st.find({cell.first-i+x, cell.second-j+y}) != st.end();
	           }
	           ++hist[sum];
	        }
	    }
	}
	int sum = 0;
	for(int i=1;i<=9;i++) hist[i] /= i, sum += hist[i];
	cout << (h-2) * (w-2) - sum << endl;
	for(int i=1;i<=9;i++) cout << hist[i]<<endl;
	return 0;
}
