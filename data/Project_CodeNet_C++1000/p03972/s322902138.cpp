#include <bits/stdc++.h>
using std::cout;
using std::endl;
using std::cin;

int main(){
	int h, w; cin >> w >> h; std::vector<std::pair<long, int>> vec;
	for(int i = 0; i < h + w; i++){
		int a; cin >> a;
		
		vec.push_back({a, i < w});
	}
	sort(begin(vec), end(vec));
	
	long A = h + 1, B = w + 1, ans = 0;
	for(int i = 0; i < h + w; i++){
		if(vec[i].second){
			if(!B) continue;
			ans += A * vec[i].first;
			B--;
		}else{
			if(!A) continue;
			ans += B * vec[i].first;
			A--;
		}
	}
	
	cout << ans << endl;
	return 0;
}
