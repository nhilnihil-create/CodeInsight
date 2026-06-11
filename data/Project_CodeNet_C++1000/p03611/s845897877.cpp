#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1e9;
using namespace std;
using ll = long long;
int cnt[100005];
int main() {
	int n;
	cin >> n;
	int a;
	while(n--){
	    cin >> a;
		cnt[a - 1]++;
		cnt[a]++;
		cnt[a + 1]++;
	}
	int max=0;
	for(int i = 0;i < 100005; i++){
		if(cnt[i] > max){
            max = cnt[i];
        }
	}
	cout << max << endl;
	return 0;
}