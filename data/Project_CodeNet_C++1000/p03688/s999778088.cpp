///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
int a[1000 * 100 + 5];
bool b[1000 * 100 + 5];
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	int n, t = 0, t1 = 0, t2 = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(!b[a[i]]){
			b[a[i]] = 1;
			t++;
		}
	}
	sort(a , a + n);
	if(a[0] == a[n - 1]){
		cout << (a[0] == n - 1 || 2 * a[0] <= n ? "Yes" : "No") << endl;
		return 0;
	}
	if(t == 2){
		for(int i = 0; i < n; i++){
			if(a[i] == a[n - 1] - 1)
				t1++;
			else
				t2++;
		}
		cout << (t1 + 1 <= a[n - 1] && t1 + t2 / 2 >= a[n - 1] ? "Yes" : "No") << endl;
	}
	else
		cout << "No" << endl;
	return 0;
}
