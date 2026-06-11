#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<int, int> P;

llint H, W, N;
vector<P> vec;
llint ans[10];

int main(void)
{
	cin >> H >> W >> N;
	llint a, b;
	for(int i = 0; i < N; i++){
		cin >> a >> b;
		for(int x = max(1LL, b-2); x <= min(b, W-2); x++){
			for(int y = max(1LL, a-2); y <= min(a, H-2); y++){
				vec.push_back( make_pair(y, x) );
			}
		}
	}
	sort(vec.begin(), vec.end());
	
	llint cnt = -1;
	P prev = make_pair(-1, -1);
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] != prev){
			if(cnt != -1) ans[cnt]++;
			cnt = 0;
		}
		prev = vec[i];
		cnt++;
	}
	if(cnt != -1) ans[cnt]++;
	
	ans[0] = (H-2)*(W-2);
	for(int i = 1; i < 10; i++) ans[0] -= ans[i];
	
	for(int i = 0; i < 10; i++){
		cout << ans[i] << endl;
	}
	return 0;
}