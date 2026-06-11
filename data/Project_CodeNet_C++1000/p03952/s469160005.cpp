#include <iostream>
#include <vector>
using namespace std;
int main(){
	int N, x;
	cin >> N >> x;
	if (x == 1 || x == N * 2 - 1){
		cout << "No" << endl;
	} else {
		vector<int> ans(N * 2 - 1, -1);
		if (x < N * 2 - 2){
			ans[N - 1] = x - 1;
			ans[N] = x;
			int num = 1;
			for (int i = 0; i < N * 2 - 1; i++){
				if (num == x - 1 || num == x){
					num = x + 1;
				}
				int pos = (N + 2 + i) % (N * 2 - 1);
				if (ans[pos] == -1){
					ans[pos] = num; 
					num++;
				}
			}
		} else {
			ans[N - 1] = x;
			ans[N] = x + 1;
			int num = 1;
			for (int i = 0; i < N * 2 - 1; i++){
				int pos = (N - 2 + i) % (N * 2 - 1);
				if (ans[pos] == -1){
					ans[pos] = num;
					num++;
				}
			}
		}
		cout << "Yes" << endl;
		for (int i = 0; i < N * 2 - 1; i++){
			cout << ans[i] << endl;
		}
	}
}