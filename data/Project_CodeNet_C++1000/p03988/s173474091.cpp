#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, a;
    cin >> n;
    multiset<ll> ms;
    for(int i=0;i<n;i++){
    	cin >> a;
    	ms.insert(a);
    }
    ll ma = *(--ms.end());

    if(ma == 1){
    	cout << ((ms.count(ma) == 2)? "Possible": "Impossible") << endl;
    	return 0;
    }

    ll mi = (ma + 1) / 2;
    for(ll i = mi + 1;i <= ma;i++){
    	if(ms.count(i) < 2){
    		cout << "Impossible" << endl;
    		return 0;
    	}
    	ms.erase(i);
    }

    if(ma & 1){
    	if(ms.size() == 2 && ms.count(mi) == 2){
    		cout << "Possible" << endl;
    	}else{
    		cout << "Impossible" << endl;
    	}
    }else{
    	if(ms.size() == 1 && ms.count(mi) == 1){
    		cout << "Possible" << endl;
    	}else{
    		cout << "Impossible" << endl;
    	}
    }
    return 0;
}
