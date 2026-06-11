#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n, m; 
int ax[100], ay[100],bx[100], by[100];
int calDist(int x1, int y1, int x2, int y2){
	return (abs(x1-x2) + abs(y1-y2));
}
int main(){
	cin>>n>>m;
	for(int i = 0; i < n; ++i)
		cin>>ax[i]>>ay[i];
	for(int i = 0; i < m; ++i)
		cin>>bx[i]>>by[i];
	for(int i = 0; i < n; ++i){
		int best = INF;
        int ans = INF;
		for(int j = 0; j<m; ++j){
			int cur = calDist(ax[i], ay[i], bx[j], by[j]);
			if(cur < best){
				best = cur;
				ans = j;
			}
		}
		cout<<ans + 1 <<endl;
	}
	return 0;
}