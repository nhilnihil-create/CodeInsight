#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;



int n;
ll a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n;

    for (int i=1; i<=n; i++) {
	cin>>a[i];
    }

    vector<int> stk;

    for (int i=n; i>=0; i--) {
	while (!stk.empty() && a[stk.back()] <= a[i]) stk.pop_back();
	stk.push_back(i);
    }



    vector<ll> ans(n+1, 0);



    priority_queue<ll> right;
    ll same = 0;
    int j=n;
    int len = stk.size();

    
    for (int i=0; i<len-1; i++) {
	int idx = stk[i];
	ll target = a[stk[i+1]];

	    
	while (j>=idx) {
	    right.push(a[j]); j--;
	}

	ll &cur = ans[idx];
	cur += same*(a[idx]-a[stk[i+1]]);

	    
	while (!right.empty() && right.top() >= target) {
	    ll x = right.top(); right.pop();
	    cur += x-target;
	    same++;
	}
    }	
    
    for (int i=1; i<=n; i++) {
	cout<<ans[i]<<"\n";
    }
    return 0;
}
