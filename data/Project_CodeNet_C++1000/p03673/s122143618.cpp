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

    int n;
    cin >> n;
    deque<int> dq;
    int a;
    for(int i=0;i<n;i++){
    	cin >> a;
    	if(i&1) dq.push_front(a);
    	else dq.push_back(a);
    }
    vector<int> v;
    if(n&1){
    	while(!dq.empty()){
    		v.pb(dq.back());
    		dq.pop_back();
    	}
    }
    else{
    	while(!dq.empty()){
    		v.pb(dq.front());
    		dq.pop_front();
    	}
    }
    for(int i: v)cout << i << " ";
    cout << endl;
    return 0;
}
