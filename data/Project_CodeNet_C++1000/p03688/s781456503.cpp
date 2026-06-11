#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;
set<int> div(int n){
	set<int> s;
	for(int i=1;i*i<=n;i++) if(n % i == 0) s.insert(i), s.insert(n/i);
	return s;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    sort(be(a));
    if(a[n-1] - a[0] >= 2){
    	cout << "No" << endl;
    	return 0;
    }
    if(a[0] == a[n-1]){
    	for(auto& i: div(n)){
    		if(i == 1 && a[0] == n - 1){
    			cout << "Yes" << endl;
    			return 0;
    		}
    		if(n/i == a[0]){
    			cout << "Yes" << endl;
    			return 0;
    		}
    	}
    	cout << "No" << endl;
    	return 0;
    }
    int mi = a[0];
    int numi = lower_bound(be(a), mi + 1) - a.begin(), numa = n - numi;
    for(auto& i: div(numa)){
    	if(i == 1){
    		continue;
    	}else{
    		if(numi - 1 + numa / i == mi){
    			cout << "Yes" << endl;
    			return 0;
    		}
    	}
    }
    cout << "No" << endl;
    return 0;
}
