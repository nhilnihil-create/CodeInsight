#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int a[100010];

signed main(){
	int n;
	cin >> n;

	for(int i = 0;i < n;i++){
		cin >> a[i];
	}

	int ans = a[0] > 0 ? 0 : 1-a[0];
	int wa = a[0] > 0 ? a[0] : 1; 
	for(int i = 1;i < n;i++){
		int nxt = abs(wa)+1;
		if(wa < 0){
			if(nxt > a[i]){
				ans += nxt-a[i];
				wa += nxt;
			}else{
				wa += a[i];
			}
		}else{
			nxt *= -1;
			if(nxt < a[i]){
				ans += a[i]-nxt;
				wa += nxt;
			}else{
				wa += a[i];
			}
		}
	}

	int ans2 = a[0] < 0 ? 0 : a[0]+1;
	wa = a[0] < 0 ? a[0] : -1;
	for(int i = 1;i < n;i++){
		int nxt = abs(wa)+1;
		if(wa < 0){
			if(nxt > a[i]){
				ans2 += nxt-a[i];
				wa += nxt;
			}else{
				wa += a[i];
			}
		}else{
			nxt *= -1;
			if(nxt < a[i]){
				ans2 += a[i]-nxt;
				wa += nxt;
			}else{
				wa += a[i];
			}
		}
	}
	cout << min(ans, ans2) << endl;

	return 0;
}
