//i hate penalty
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

pair<int, int> a[100001];

int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++){
		int x;
		cin >> x;
		a[i]=make_pair(x, i);
	}
	sort(a, a+n);
	int ans=0;
	for (int i=0; i<n; i++){
		if (a[i].s%2!=i%2){
			if (a[i].s%2) ans+=2;
			else ans--;
		}
	}
	cout << ans << "\n";
}