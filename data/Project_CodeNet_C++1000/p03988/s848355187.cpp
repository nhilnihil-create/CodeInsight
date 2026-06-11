///A drunk man will find his way home, but a drunk bird may get lost forever...i
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define pf push_front
#define f first
#define s second
#define sz(x) (int)x.size()
#define smin(x , y) x = min(x , y)
#define mp make_pair
//const int mx = 2000 * 100;
int t[110];
int32_t main(){		
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	int n, k = 0, a;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		t[a]++;
		k = max(k , a);
	}
	if(k % 2 == 0){
		for(int i = k; i > k / 2; i--){
			if(t[i] < 2){
				cout << "Impossible" << endl;
				return 0;
			}
			t[i] -= 2;
		}
		if(t[k / 2] < 1){
			cout << "Impossible" << endl;
			return 0;
		}
		t[k / 2]--;
		for(int i = 1; i <= 100; i++){
			if(t[i] && i < k / 2 + 1){
				cout << "Impossible" << endl;
				return 0;
			}
		}
		cout << "Possible" << endl;
		return 0;
	}
	for(int i = k; i >= (k + 1)/ 2; i--){
		if(t[i] < 2){
			cout << "Impossible" << endl;
			return 0;
		}
		t[i] -= 2;
	}
	for(int i = 1; i <= 100; i++){
		if(t[i] && i < (k + 1) / 2 + 1){
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << "Possible" << endl;

	return 0;
}
