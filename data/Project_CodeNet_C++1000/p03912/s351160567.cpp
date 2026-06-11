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
    int n, m, a, MAX = 100000, ans = 0;
    cin >> n >> m;
    vector<vector<int> > x(m, vector<int> (2,0));
    vector<int> b(MAX + 1, 0);
    for(int i=0;i<n;i++) cin >> a, b[a]++;
    for(int i=1;i<=MAX;i++){
    	x[i % m][1] += b[i] / 2;
    	x[i % m][0] += b[i] & 1;
    }
    for(int i=0;i<=m/2;i++){
    	if(i * 2 == m || i == 0){
    		ans += x[i][0] / 2;
    		ans += x[i][1];
    		continue;
     	}
     	int j = m - i;
     	if(x[i][0] == x[j][0]){
     		ans += x[i][0];
     		ans += x[i][1];
     		ans += x[j][1];
     		continue;
     	}
     	if(x[i][0] < x[j][0]){
     		swap(x[i][0], x[j][0]);
     		swap(x[i][1], x[j][1]);
     	}
     	ans += x[j][0];
     	x[i][0] -= x[j][0];
     	ans += x[i][1];
     	int num = x[j][1] * 2;
     	if(x[i][0] >= num){
     		ans += num;
     	}else{
     	    ans += x[i][0];
     		num -= x[i][0];
     		ans += num / 2;
     	}
    }
    cout << ans << endl;
    return 0;
}
