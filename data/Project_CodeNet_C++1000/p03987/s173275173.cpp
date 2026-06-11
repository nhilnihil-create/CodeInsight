#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define F first
#define S second
#define pb push_back
#define ll long long
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll n,a[200008],r[200008],l[200008],ans;
stack <ll> st;
stack <ll> stt;

int main() {
	faster;
	cin>>n;
	for (int i = 1; i<=n; i++) {
		cin>>a[i];
	}
	for (int i = 1; i<=n; i++) {
		while (!st.empty() && a[st.top()]>=a[i]) {
			st.pop();
		}
		if (st.empty()) {
			l[i] = 0;
		}
		else {
			l[i] = st.top();
		}
		st.push(i);
	}
	for (int i = n; i>=1; i--) {
		while (!stt.empty() && a[stt.top()]>=a[i]) {
			stt.pop();
		}
		if (stt.empty()) {
			r[i] = n+1;
		}
		else {
			r[i] = stt.top();
		}
		stt.push(i);
	}
	for (int i = 1; i<=n; i++) {
		//cout<<l[i]<<' '<<r[i]<<endl;
		ll id = (r[i]-i)*(i-l[i]);
		ans+= id*a[i];
	}
	cout<<ans;

    return 0;
}
