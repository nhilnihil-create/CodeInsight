#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2000006;
const ll MOD = 1e9+7;

int n;
int nxt[N],prv[N];
int a[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0] = a[n+1] = -1;
	stack<int> st;
	
	for(int i=0;i<=n+1;i++){
		while(!st.empty() && a[i] < a[st.top()]){
			nxt[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	
	while(!st.empty())st.pop();
	for(int i=n+1;i>=0;i--){
		while(!st.empty() && a[i] < a[st.top()]){
			prv[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	
	ll ans = 0;
	for(int i=1;i<=n;i++){
		ll x = i - prv[i];
		ll y = nxt[i] - i;
		ans += x * y * a[i];
	}
	
	cout<<ans;
	
	return 0;
}
