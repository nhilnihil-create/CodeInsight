#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n);
	vector<vector<int>> hw(h, vector<int>(w));
	rep(i, n) cin >> a[i];
	int now_a = 0;
	rep(i, h){
		int suji = now_a;
		if(i%2==0){
			for(int j=0; j<w; j++){
				hw[i][j] = suji;
				a[now_a]--;
				if(a[now_a] <= 0){
					now_a++;
					suji = now_a;
				}
			}
		}else{
			for(int j=w-1; j>=0; j--){
				hw[i][j] = suji;
				a[now_a]--;
				if(a[now_a] <= 0){
					now_a++;
					suji = now_a;
				}
			}
		}
	}
	rep(i, h){
		rep(j, w){
			cout << hw[i][j]+1 << " ";
		}
		cout << endl;
	}
	return 0;
}