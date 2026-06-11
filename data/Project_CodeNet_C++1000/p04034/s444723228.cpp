#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int N,M;
	cin >> N >> M;
	vector<int> B(N,1);
	vector<bool> R(N,false);
	R[0] = true;

	for(int i=0; i<M; i++){
		int x,y; cin >> x >> y;
		if(R[x-1]){
			B[x-1]--; B[y-1]++;
			R[y-1]=true;
			if(B[x-1] == 0)R[x-1]=false;
		} else {
			B[x-1]--; B[y-1]++;
		}
	}
	int ans = 0;
	for(int i=0; i<N; i++) if(R[i])ans++;
	cout << ans << endl;
	return 0;
}

