///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define int long long
#define sz(x) (int)x.size()
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n, x, j = 1;
	cin >> n >> x;
	if(x == 1 || x == 2 * n - 1){
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for(int i = 0; i < n - 2; i++){
		if(j == x - 1)
			j += 3;
		cout << j << " ";
		j++;
	}
	cout << x - 1 << " " << x << " " << x + 1 << " ";
	for(int i = 0; i < n - 2; i++){
		if(j == x - 1)
			j += 3;
		cout << j << " ";
		j++;
	}
	return 0;
}
