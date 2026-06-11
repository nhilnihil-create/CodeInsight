#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    bool col[8];
    memset(col, 0,sizeof(col));
    ll n;
    cin >> n;
    bool maki= 0;
    ll a, cnt = 0;
    for(int i=0;i<n;i++){
    	cin >> a;
    	a /= 400;
    	if(a >= 8LL){
    		cnt++;
    	}else{
    		col[a]=true;
    		maki = true;
    	}
    }
    if(!maki){
    	cout << 1 << " " << cnt << endl;
    }else{
    	ll num = 0;
    	for(int i=0;i<8;i++){
    		if(col[i]) num++;
    	}
    	cout << num << " " << num + cnt << endl;
    }
    return 0;
}
