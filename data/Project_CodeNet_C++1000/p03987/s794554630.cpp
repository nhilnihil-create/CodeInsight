#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2000006;
const ll MOD = 1e9+7;

int n;
int a[N];
int idx[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		idx[a[i]] = i;
	}
	
	ll ans = 0;
	ll x = n - idx[1] + 1;
	ll y = idx[1];
	ans += x*y;
	set<int> st;
	st.insert(idx[1]);
	
	for(int i=2;i<=n;i++){
		if( idx[i] < *st.begin()){
			x = *st.begin() - idx[i];
			y = idx[i];
			ans += x * y * i;
			st.insert(idx[i]);
			//cout<<i<<" "<<x<<" "<<y<<endl;
			continue;
		}
		if(idx[i] > *st.rbegin()){
			x = n - idx[i] + 1;
			y = idx[i] - *st.rbegin();
			ans += x * y * i;
			st.insert(idx[i]);
			//cout<<i<<" "<<x<<" "<<y<<endl;
			continue;
		}
		x = *(st.upper_bound(idx[i])) - idx[i];
		y = idx[i] - *(--st.upper_bound(idx[i]));
		ans += x * y * i;
		//cout<<i<<" "<<x<<" "<<y<<endl;
		st.insert(idx[i]);
	}
	
	cout<<ans;
	
	return 0;
}
