#include <bits/stdc++.h>

using namespace std;

#define INF 210000000
#define int long long

signed main() {
		int h,w;
		cin >> h >> w;
		int n;
		cin >> n;
		vector<int> a;
		for(int i=0;i<n;i++){
				int tmp;
				cin >> tmp;
				a.push_back(tmp);
		}
		vector<vector<int>> ans;
		int cnt = 0;
		int color_cnt = a[0];
		int color = 1;
		for(int i=0;i<h;i++){
				vector<int> tmp;
				for(int j=0;j<w;j++){
						auto begin = tmp.begin();
						if(i % 2 == 0){
								tmp.push_back(color);
						}else{
								tmp.insert(begin,color);
						}
						cnt++;
						if(cnt >= color_cnt){
								color_cnt += a[color];
								color++;
						}
				}
				ans.push_back(tmp);
		}
		for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
						cout << ans[i][j];
						cout << ' ';
				}
				cout << "\n";
		}
}
