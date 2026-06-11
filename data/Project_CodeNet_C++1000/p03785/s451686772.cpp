#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int N,C,K;
	cin >> N >> C >> K;
	vector<int> T(N);
	for(int i=0;  i<N; i++) cin >> T[i];
	sort(T.begin(),T.end());

	int ans = 0;
	int i = 0;
	while(i<N){
		ans++;
		int a = T[i]+K;
		int p = i;
		for(int j=0; j<C; j++){
			if(T[p+j] > a)break;
			i++;
		}
	}

	cout << ans << endl;
	return 0;
}

