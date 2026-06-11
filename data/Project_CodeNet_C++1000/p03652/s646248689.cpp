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
    int n, m, a;
    cin >> n >> m;
    queue<int> q[n];
    
    for(int i=0;i<n;i++){
    	for(int j=0;j<m;j++){
    		cin >> a;
    		q[i].push(a - 1);
    	}
    }

    bool fin[m];
    memset(fin,0,sizeof(fin));

    int ans = n;
    bool maki = true;

    while(maki){
        vector<int> cnt(m, 0);
        for(int i=0;i<n;i++) cnt[q[i].front()]++;
        int num = 0, id = 0;
        for(int i=0;i<m;i++) {
        	if(num < cnt[i]) num = cnt[i], id = i;
        }
        ans = min(ans, num);
        fin[id] = true;
        
        for(int i=0;i<n;i++){
        	while(!q[i].empty() && fin[q[i].front()]) q[i].pop();
        	if(q[i].empty()) maki = false;
        }
    }
    cout << ans << endl;
    return 0;
}
